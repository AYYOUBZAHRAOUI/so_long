/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:27:30 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 02:52:35 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft(void)
{
	system("leaks so_long");
}

int main(int argc, char **argv)
{
	atexit(ft);
	t_map	*map;

	if (argc != 2)
		return(write(2, "Error: put just one argument.\n", 30), 1);
	check_extention(argv[1]);
	map = malloc(sizeof(t_map));
	ft_memset(map,0,sizeof(t_map));
	get_map(argv[1],map);
	check_map(map);
	map->x = mlx_init((60*(map->cols)), (60*(map->rows)), "So_long", 1);
	rendering_map(map);
	mlx_key_hook(map->x, keys_handel, map);
	mlx_loop(map->x);
	mlx_terminate(map->x);
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
