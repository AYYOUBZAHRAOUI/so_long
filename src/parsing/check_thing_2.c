/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:24:46 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 23:10:50 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

// this function take the map struct and check if the map have
// a wall around it
void	have_wall_around(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->arr[++i])
	{
		j = -1;
		while (map->arr[i][++j])
		{
			if (i == 0 || i == map->rows - 1 || j == 0 || j == map->cols - 1)
			{
				if (map->arr[i][j] != '1')
				{
					free_arr(map->arr);
					write(2, "Error\nmap must have a wall around it.\n", 39);
					exit(1);
				}
			}
		}
	}
}

// this function take the map struct and check if the map
// return to the player position
void	get_player_position(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->arr[++i])
	{
		j = -1;
		while (map->arr[i][++j])
		{
			if (map->arr[i][j] == 'P')
			{
				map->player.x = j;
				map->player.y = i;
				break ;
			}
		}
	}
}

// this function create the copy of the map->arr and the player position
// and fill the map with 'T' where the player can access
// and check if the player can access all the map
void	player_access_map(t_map *map)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = copy_map(map);
	player_access_all_map(copy, map->player.x, map->player.y);
	while (i < map->rows)
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'P')
			{
				free_arr(map->arr);
				free_arr_v2(copy, map->rows);
				exit(write(2, "Error\nplayer can't access all the map.\n", 40));
			}
			j++;
		}
		i++;
	}
	free_arr_v2(copy, map->rows);
}

void	rectangular(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->cols = ft_strlen(map->arr[i]);
	while (i < map->rows)
	{
		j = ft_strlen(map->arr[i]);
		if (j != map->cols)
		{
			free_arr(map->arr);
			exit(write(2, "Error\nthe map must be rectangular\n", 34));
		}
		i++;
	}
}

// this function take the map struct
// and check if the map is valid
void	check_map(t_map *map)
{
	rectangular(map);
	have_valid_characters(map);
	have_one_player_and_exit(map);
	have_wall_around(map);
	get_player_position(map);
	player_access_map(map);
}
