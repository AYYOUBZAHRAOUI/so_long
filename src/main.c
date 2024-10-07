/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:27:30 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 23:34:41 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (write(2, "Error\nput just one argument.\n", 29), 1);
	check_extention(argv[1]);
	get_map(argv[1], &map);
	check_map(&map);
	map.x = mlx_init((60 * (map.cols)), (60 * (map.rows)), "So_long", 1);
	rendering_map(&map);
	mlx_key_hook(map.x, keys_handel, &map);
	mlx_close_hook(map.x, close_handel, &map);
	mlx_loop(map.x);
	mlx_terminate(map.x);
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
