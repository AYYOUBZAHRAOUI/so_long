/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:19:17 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 22:42:20 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

// this fuction take the file name and the map struct
// and fill the map struct with the map information
void	get_map_in_arr(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	*big_line;
	int		i;

	i = 0;
	big_line = ft_calloc(sizeof(char *), 1); 
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(big_line);
		exit(write(2, "Error\nfile doesn't found\n", 25));
	}
	line = get_next_line(fd);
	while (line && ++i)
	{
		big_line = ft_strjoin_free(big_line, line);
		free(line);
		line = get_next_line(fd);
	}
	map->rows = i;
	map->arr = ft_split(big_line, '\n');
	free(big_line);
	close(fd);
}

void	row(t_map *map)
{
	int	i;

	i = 0;
	while (map->arr[i])
		i++;
	if (map->rows != i)
	{
		free_arr(map->arr);
		exit(write(2, "Error\nYou have empty lines in map file.\n", 40));
	}
}

// this fuction take the map struct and fill the collectibles variable
// and check if the map has collectibles
void	get_map_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->collectibles = 0;
	while (map->arr[++i])
	{
		j = -1;
		while (map->arr[i][++j])
		{
			if (map->arr[i][j] == 'C')
				map->collectibles++;
		}
	}
	if (map->collectibles == 0)
	{
		free_arr((map->arr));
		exit(write(2, "Error\nmap has no collectibles or is empty.\n", 43));
	}
}

// this fuction create a map struct and fill it with the map information
// and return the map struct
void	get_map(char *file_name, t_map *map)
{
	get_map_in_arr(file_name, map);
	row(map);
	get_map_collectibles(map);
}
