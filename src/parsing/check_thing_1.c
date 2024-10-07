/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_thing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:08:43 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 23:09:30 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

// this fuction take the file name and check if the extention is valid
int	check_extention(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if ((i < 5) 
		|| file_name[i - 1] != 'r' || file_name[i - 2] != 'e' 
		|| file_name[i - 3] != 'b' || file_name[i - 4] != '.')
	{
		write(2, "Error\nput a valid file name.\n", 29);
		exit(1);
	}
	return (1);
}

// this fuction take a char **arr and free it
void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}

void	free_arr_v2(char **arr, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(arr[i++]);
	}
	free(arr);
}

// this function take the map struct and return a copy of the map->arr
// this NULL terminator give me a segmentation fault
char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * map->rows);
	i = 0;
	while (map->arr[i])
	{
		copy[i] = ft_strdup(map->arr[i]);
		i++;
	}
	return (copy);
}

// this function take a copy of the map->arr and the player position
// and fill the map with 'T' where the player can access
void	player_access_all_map(char **maparr, int x, int y)
{
	if (maparr[y][x] == '1' || maparr[y][x] == 'T'
		|| maparr[y][x] == 'E')
		return ;
	if (maparr[y][x] == 'P')
		maparr[y][x] = 'T';
	if (maparr[y][x] == 'C')
		maparr[y][x] = 'T';
	if (maparr[y][x] == '0')
		maparr[y][x] = 'T';
	player_access_all_map(maparr, x + 1, y);
	player_access_all_map(maparr, x - 1, y);
	player_access_all_map(maparr, x, y + 1);
	player_access_all_map(maparr, x, y - 1);
}
