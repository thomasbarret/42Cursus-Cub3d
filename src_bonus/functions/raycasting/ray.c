/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:46 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/01 18:41:22 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	inter_check(float angle, float *inter, float *step, int is_h)
{
	if (is_h)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += T_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += T_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

static float	get_h_inter(t_game *game, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		p;

	y_step = T_SIZE;
	x_step = T_SIZE / tan(angle);
	h_y = floor(game->player.y / T_SIZE) * T_SIZE;
	p = inter_check(angle, &h_y, &y_step, 1);
	h_x = game->player.x + (h_y - game->player.y) / tan(angle);
	if ((unit_circle('y', angle) && x_step > 0)
		|| (!unit_circle('y', angle) && x_step < 0))
		x_step *= -1;
	while (ray_hit_wall(game, h_x, h_y - p))
	{
		h_x += x_step;
		h_y += y_step;
	}
	game->ray.h_x = h_x;
	return (sqrt(pow(h_x - game->player.x, 2) + pow(h_y - game->player.y, 2)));
}

static float	get_v_inter(t_game *game, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = T_SIZE;
	y_step = T_SIZE * tan(angl);
	v_x = floor(game->player.x / T_SIZE) * T_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = game->player.y + (v_x - game->player.x) * tan(angl);
	if ((unit_circle('x', angl) && y_step < 0)
		|| (!unit_circle('x', angl) && y_step > 0))
		y_step *= -1;
	while (ray_hit_wall(game, v_x - pixel, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}
	game->ray.v_y = v_y;
	return (sqrt(pow(v_x - game->player.x, 2) + pow(v_y - game->player.y, 2)));
}

void	ray(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	game->ray.angle = game->player.angle - (game->player.fov / 2);
	while (ray < S_W)
	{
		game->ray.hit = 0;
		h_inter = get_h_inter(game, radiant_angle(game->ray.angle));
		v_inter = get_v_inter(game, radiant_angle(game->ray.angle));
		if (v_inter <= h_inter)
			game->ray.distance = v_inter;
		else
		{
			game->ray.distance = h_inter;
			game->ray.hit = 1;
		}
		render_wall(game, ray);
		ray++;
		game->ray.angle += (game->player.fov / S_W);
	}
}
