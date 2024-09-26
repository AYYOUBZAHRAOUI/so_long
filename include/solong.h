/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzahrao <ayzahrao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:58:20 by ayzahrao          #+#    #+#             */
/*   Updated: 2024/09/26 01:25:13 by ayzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SOLONG_H

# define SOLONG_H

# include <stdio.h>
# include "../libft/include/libft.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "MLX42.h"
# include <fcntl.h>

typedef struct s_player
{
	int		x;
	int		y;
} t_player;
typedef struct s_images
{
	mlx_image_t *pl;
	mlx_image_t *ex;
	mlx_image_t *col;
	mlx_image_t *wl;
	mlx_image_t *bg;
	
} t_images;

typedef struct s_textures
{
	mlx_texture_t *pl;
	mlx_texture_t *ex;
	mlx_texture_t *col;
	mlx_texture_t *wl;
	mlx_texture_t *bg;
} t_textures;

typedef struct s_map
{
	char	**arr;
	int		rows; // this is max y
	int		cols; // this is max x
	int		collectibles;
	t_player player;
	t_images *images;
	t_textures *textures;
	mlx_t *x;
} t_map;

// get_map.c functions have more 4 static functions
void get_map(char *file_name, t_map *map);
void free_arr_v2(char **arr, int x);
// check_thing.c functions
int check_extention(char *file_name);
void free_arr(char **arr);
int ft_map_strlen(char *str);

// check_thing.c functions have more 2 static functions
void have_one_player_and_exit(t_map *map);
void have_valid_characters(t_map *map);
void have_wall_around(t_map *map);
void get_player_position(t_map *map);
void player_access_map(t_map *map);
void check_map(t_map *map);
char	*ft_strjoin_free(char *s1, char *s2);

// 
// void put_player(mlx_t *x, t_map *map);
// void put_background(mlx_t *x, t_map *map);
// void put_collectible(mlx_t *x, t_map *map);
// void put_exit(mlx_t *x, t_map *map);
// void put_wall(mlx_t *x, t_map *map);
// void show_map(t_map *map);
void rendering_map(t_map *map);
void load_textures_images(t_map *map);
void keys_handel(mlx_key_data_t key, void *map);
void move(t_map *map, int x, int y);
void	ft_free(t_map *map, char **str);

#endif

