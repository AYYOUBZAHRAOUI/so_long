/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:05:41 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 02:49:41 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

void free_map_exit(t_map *map)
{
	free_arr(map->arr);
	mlx_close_window(map->x);
	mlx_terminate(map->x);
	free(map);
	exit(1);
}

void	put_nbr(int x)
{
	char		*digit;

	digit = "0123456789";
	if (x >= 10)
		put_nbr(x / 10);
	write(1, digit + (x % 10), 1);
}

void count_moves(void)
{
	static int x;
	
	x++;
	write(1, "move : ", 8);
	put_nbr(x);
	write(1, "\n", 1);
}

void keys_handel(mlx_key_data_t key, void *map)
{	
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
			move(map, -60, 0);
		else if (key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
			move(map, 60, 0);
		else if (key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
			move(map, 0, -60);
		else if (key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
			move(map, 0, 60);
		else if (key.key == MLX_KEY_ESCAPE)
		{
			free_map_exit(map);
		}
	}
}

void move(t_map *map, int x, int y)
{
	int new_pos_x;
	int new_pos_y;

	new_pos_x = map->player.x + (x / 60);
	new_pos_y = map->player.y + (y /60);
	if (map->arr[new_pos_y][new_pos_x] != '1' && map->arr[new_pos_y][new_pos_x] != 'E')
	{
		count_moves();
		if (map->arr[new_pos_y][new_pos_x] == 'C' && map->collectibles--)
			map->arr[new_pos_y][new_pos_x] = '0';
		mlx_image_to_window(map->x, map->images->bg, new_pos_x*60, new_pos_y*60);
		mlx_image_to_window(map->x, map->images->pl, new_pos_x*60, new_pos_y*60);
		mlx_image_to_window(map->x, map->images->bg, map->player.x*60, map->player.y*60);
		map->player.x = new_pos_x;
		map->player.y = new_pos_y;
	}
	if (map->collectibles == 0)
	{
		if (map->arr[new_pos_y][new_pos_x] == 'E')
		{
			count_moves();
			free_map_exit(map);
		}
			
	}
}
