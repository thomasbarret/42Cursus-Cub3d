/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:38:29 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/01 19:20:28 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	rotate(t_game *game, int i);
static void	move(t_game *game, double move_x, double move_y);
static void	set_player_direction(t_game *game, double m_x, double m_y);

static void	move(t_game *game, double move_x, double move_y)
{
	int		map_y;
	int		map_x;
	int		new_x;
	int		new_y;

	new_x = roundf(game->player.x + move_x);
	new_y = roundf(game->player.y + move_y);
	map_x = (new_x / T_SIZE);
	map_y = (new_y / T_SIZE);
	if (game->map.content[map_y][map_x] != '1'
		&& (game->map.content[map_y][game->player.x / T_SIZE] != '1'
		&& game->map.content[game->player.y / T_SIZE][map_x] != '1'))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

static void	rotate(t_game *game, int i)
{
	if (i == 1)
	{
		game->player.angle += R_SPEED;
		if (game->player.angle > 2 * M_PI)
			game->player.angle -= 2 * M_PI;
	}
	else
	{
		game->player.angle -= R_SPEED;
		if (game->player.angle < 0)
			game->player.angle += 2 * M_PI;
	}
}

void	mouvement(t_game *game)
{
	double	m_x;
	double	m_y;

	m_x = 0;
	m_y = 0;
	if (game->player.r == 1)
		rotate(game, 1);
	if (game->player.r == -1)
		rotate(game, 0);
	set_player_direction(game, m_x, m_y);
}

static void	set_player_direction(t_game *game, double m_x, double m_y)
{
	if (game->player.l_or_r == 1)
	{
		m_x = -sin(game->player.angle) * P_SPEED;
		m_y = cos(game->player.angle) * P_SPEED;
	}
	if (game->player.l_or_r == -1)
	{
		m_x = sin(game->player.angle) * P_SPEED;
		m_y = -cos(game->player.angle) * P_SPEED;
	}
	if (game->player.f_or_b == 1)
	{
		m_x = cos(game->player.angle) * P_SPEED;
		m_y = sin(game->player.angle) * P_SPEED;
	}
	if (game->player.f_or_b == -1)
	{
		m_x = -cos(game->player.angle) * P_SPEED;
		m_y = -sin(game->player.angle) * P_SPEED;
	}
	move(game, m_x, m_y);
}
