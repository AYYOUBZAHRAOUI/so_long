/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:08:43 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/25 02:47:24 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/solong.h"

// this fuction take the file name and check if the extention is valid
int check_extention(char *file_name)
{
	int i;

	i = ft_strlen(file_name);
	if ((i < 5) 
		|| file_name[i - 1] != 'r' || file_name[i - 2] != 'e' 
		|| file_name[i - 3] != 'b' || file_name[i - 4] != '.')
	{
		write(2, "Error: put a valid file name.\n", 30);
		exit(1);
	}
	return (1);
}

// this fuction take a char **arr and free it
void free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}

void free_arr_v2(char **arr, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		free(arr[i++]);
	}
	free(arr);
}