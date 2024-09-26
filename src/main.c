/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:27:30 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 15:07:51 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft(void)
{
	system("leaks so_long");
}

void free_images_and_textures(t_map *map)
{
	free(map->images->bg);
	free(map->images->col);
	free(map->images->wl);
	free(map->images->pl);
	free(map->images->ex);
	free(map->textures->bg);
	free(map->textures->col);
	free(map->textures->wl);
	free(map->textures->pl);
	free(map->textures->ex);
	free(map->images);
	free(map->textures);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	atexit(ft);
	if (argc != 2)
		return (write(2, "Error: put just one argument.\n", 30), 1);
	check_extention(argv[1]);
	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	get_map(argv[1], map);
	check_map(map);

	map->x = mlx_init((60 * (map->cols)), (60 * (map->rows)), "So_long", 1);
	rendering_map(map);
	free_images_and_textures(map);
	free_arr(map->arr);
	free(map);
	// mlx_key_hook(map->x, keys_handel, map);
	// mlx_loop(map->x);
	// mlx_terminate(map->x);
	return (0);
}


char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*p;
	int		i1;
	int		i2;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	p = (char *)malloc(i1 + i2 + 1);
	ft_memcpy(p, s1, i1);
	ft_memcpy(p + i1, s2, i2 + 1);
	free(s1);
	return (p);
}
