/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 02:18:44 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 06:09:07 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"
#include "../include/MLX42.h"

void	fill_background(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j])
		{
			mlx_image_to_window(map->x, map->images->bg, j * 60, i * 60);
			if (map->arr[i][j] == '1')
				mlx_image_to_window(map->x, map->images->wl, j * 60, i * 60);
			if (map->arr[i][j] == 'P')
				mlx_image_to_window(map->x, map->images->pl, j * 60, i * 60);
			if (map->arr[i][j] == 'E')
				mlx_image_to_window(map->x, map->images->ex, j * 60, i * 60);
			if (map->arr[i][j] == 'C')
				mlx_image_to_window(map->x, map->images->col,
					j * 60 + 10, i * 60 + 10);
			j++;
		}
		i++;
	}
}

void	textures_error(t_map *map)
{
	if (map->textures->pl == NULL || map->textures->ex == NULL
		|| map->textures->bg == NULL || map->textures->col == NULL
		|| map->textures->wl == NULL)
	{
		free_arr(map->arr);
		mlx_close_window(map->x);
		free(map);
		exit(write(2, "Error\nthe PNG not found\n", 24));
	}
}

void	load_textures_images(t_map *map)
{
	map->images = malloc(sizeof(t_images));
	map->textures = malloc(sizeof(t_textures));
	map->textures->pl = mlx_load_png("imgs/player.png");
	map->textures->ex = mlx_load_png("imgs/exit.png");
	map->textures->col = mlx_load_png("imgs/coin.png");
	map->textures->wl = mlx_load_png("imgs/wall.png");
	map->textures->bg = mlx_load_png("imgs/background.png");
	textures_error(map);
	map->images->pl = mlx_texture_to_image(map->x, map->textures->pl);
	map->images->bg = mlx_texture_to_image(map->x, map->textures->bg);
	map->images->wl = mlx_texture_to_image(map->x, map->textures->wl);
	map->images->col = mlx_texture_to_image(map->x, map->textures->col);
	map->images->ex = mlx_texture_to_image(map->x, map->textures->ex);
}

void	rendering_map(t_map *map)
{
	load_textures_images(map);
	fill_background(map);
}
