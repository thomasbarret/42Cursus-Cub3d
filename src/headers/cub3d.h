/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:29:07 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/27 12:34:03 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "error.h"
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include "../../libs/mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# define S_W 950
# define S_H 500
# define T_SIZE 32
# define FOV 60
# define R_SPEED 0.010
# define P_SPEED 1

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115

typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	double	fov;
	int		r;
	int		l_or_r;
	int		f_or_b;
}	t_player;

typedef struct s_map
{
	char	**content;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_map;

typedef struct s_ray
{
	int		i;
	double	angle;
	double	distance;
	int		hit;
	float	h_x;
	float	v_y;
}	t_ray;

typedef struct s_img
{
	char	*path;
	int		width;
	int		height;
	void	*buffer;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx_init;
	void		*mlx_win;
	t_img		frame;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_img		img[4];
	int			floor_color;
	int			ceiling_color;
}	t_game;

//utils.c
void	ft_error(t_game *game, char *str);
void	ft_free_tab(char **r);
void	free_img(t_game *game, t_img *r);
char	**copy_tab(char **tab);
int		count_tab(char **tab);
//file.c
void	file_condition(t_game *game, char *path);

//map.c
void	map_condition(t_game *game, char **file);

//player.c
void	find_player(t_game *game, char **map);
int		is_player(char t);
char	*ft_strnew(int size);
void	same_size(t_game *game, char **map, int width);

//image.c
void	init_img(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);
t_img	get_wall_texture(t_game *game, int hit);

// raycasting/mouvement.c  
void	mouvement(t_game *game);

// raycasting/drawing.c
void	render_wall(t_game *game, int ray);

// raycasting/ray.c
void	ray(t_game *game);
int		ray_hit_wall(t_game *game, float x, float y);
// raycasting/math.c
int		unit_circle(char a, float angle);
float	radiant_angle(float angle);

// utils_file.c
void	check_line(char *r, char **l);
void	catching_join(t_game *game, char ***map, int i, char **line);

#endif