/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thing_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:11:46 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 23:25:51 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

// this function take the map struct and check if the map have
// only one player and one exit
void	have_one_player_and_exit(t_map *map)
{
	int	i;
	int	j;
	int	player;
	int	exi;

	i = -1;
	player = 0;
	exi = 0;
	while (map->arr[++i])
	{
		j = -1;
		while (map->arr[i][++j])
		{
			if (map->arr[i][j] == 'P')
				player++;
			if (map->arr[i][j] == 'E')
				exi++;
		}
	}
	if (player != 1 || exi != 1)
	{
		free_arr(map->arr);
		exit(write(2, "Error\nmap must have one player and one exit.\n", 45));
	}
}

// this function take the map struct and check if the map have
// any invalid character
void	have_valid_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j])
		{
			if (map->arr[i][j] != '1' && map->arr[i][j] != '0' 
				&& map->arr[i][j] != 'P' && map->arr[i][j] != 'E' 
				&& map->arr[i][j] != 'C' && map->arr[i][j] != '\n')
			{
				free_arr(map->arr);
				exit(write(2, "Error\nmap has invalid characters.\n", 34));
			}
			j++;
		}
		i++;
	}
}
