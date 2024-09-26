/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:05:41 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 14:48:12 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

void	free_map_exit(t_map *map)
{
	free_arr(map->arr);
	mlx_close_window(map->x);
	mlx_terminate(map->x);
	// free(map->images);
	// free(map->textures);
	free(map);
	exit(1);
}

void	put_nbr(int x)
{
	char	*digit;

	digit = "0123456789";
	if (x >= 10)
		put_nbr(x / 10);
	write(1, digit + (x % 10), 1);
}

void	count_moves(void)
{
	static int	x;

	x++;
	write(1, "move : ", 8);
	put_nbr(x);
	write(1, "\n", 1);
}

void	keys_handel(mlx_key_data_t key, void *map)
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

void	move(t_map *map, int x, int y)
{
	int	nx;
	int	ny;

	nx = map->player.x + (x / 60);
	ny = map->player.y + (y / 60);
	if (map->arr[ny][nx] != '1' && map->arr[ny][nx] != 'E')
	{
		count_moves();
		if (map->arr[ny][nx] == 'C' && map->collectibles--)
			map->arr[ny][nx] = '0';
		mlx_image_to_window(map->x, map->images->bg, nx * 60, ny * 60);
		mlx_image_to_window(map->x, map->images->pl, nx * 60, ny * 60);
		mlx_image_to_window(map->x, map->images->bg, map->player.x * 60,
			map->player.y * 60);
		map->player.x = nx;
		map->player.y = ny;
	}
	if (map->collectibles == 0)
	{
		if (map->arr[ny][nx] == 'E')
		{
			count_moves();
			free_map_exit(map);
		}
	}
}
