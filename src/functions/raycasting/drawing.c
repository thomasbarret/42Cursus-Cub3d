/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:48:09 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/01 18:39:38 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static double	get_img_x(t_img *img, t_game *game);
static void		draw_wall(t_game *game, int t_p, int b_p, double wall_h);
static void		draw_floor_ceiling(t_game *game, int t_p, int b_p);

int	ray_hit_wall(t_game *game, float x, float y)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / T_SIZE);
	y_m = floor(y / T_SIZE);
	if ((y_m >= game->map.height || x_m >= game->map.width))
		return (0);
	if (game->map.content[y_m] && x_m <= (int)ft_strlen(game->map.content[y_m]))
		if (game->map.content[y_m][x_m] == '1')
			return (0);
	return (1);
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	b_p;
	double	t_p;

	game->ray.distance
		*= cos(radiant_angle(game->ray.angle - game->player.angle));
	wall_h
		= (T_SIZE / game->ray.distance)
		* ((S_W / 2) / tan(game->player.fov / 2));
	b_p = (S_H / 2) + (wall_h / 2);
	t_p = (S_H / 2) - (wall_h / 2);
	if (b_p > S_H)
		b_p = S_H;
	if (t_p < 0)
		t_p = 0;
	game->ray.i = ray;
	draw_wall(game, t_p, b_p, wall_h);
	draw_floor_ceiling(game, t_p, b_p);
}

static void	draw_floor_ceiling(t_game *game, int t_p, int b_p)
{
	int		i;

	i = b_p;
	while (i < S_H)
		put_pixel(game, game->ray.i, i++, game->floor_color);
	i = 0;
	while (i < t_p)
		put_pixel(game, game->ray.i, i++, game->ceiling_color);
}

static double	get_img_x(t_img *img, t_game *game)
{
	double	x;

	if (game->ray.hit == 1)
		x = (int)fmodf((game->ray.h_x * (img->width / T_SIZE)), img->width);
	else
		x = (int)fmodf((game->ray.v_y * (img->width / T_SIZE)), img->width);
	return (x);
}

static void	draw_wall(t_game *game, int t_p, int b_p, double wall_h)
{
	t_img	img;
	double	y;
	double	x;
	double	factor;

	img = get_wall_texture(game, game->ray.hit);
	factor = (double)(img.height / wall_h);
	x = get_img_x(&img, game);
	y = (t_p - (S_H / 2) + (wall_h / 2)) * factor;
	if (y < 0)
		y = 0;
	while (t_p < b_p)
	{
		put_pixel(game, game->ray.i, t_p,
			img.addr[(int)y * img.height + (int)x]);
		y += factor;
		t_p++;
	}
}
