/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:25:34 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/01 18:23:12 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->img[i].buffer = mlx_xpm_file_to_image(game->mlx_init,
				game->img[i].path, &game->img[i].width, &game->img[i].height);
		if (!game->img[i].buffer)
			return (ft_error(game, ERR_TEXTURE));
		game->img[i].addr = (int *)mlx_get_data_addr(game->img[i].buffer,
				&(game->img[i].bpp),
				&(game->img[i].size_line), &(game->img[i].endian));
		if (!game->img[i].addr)
			return (ft_error(game, ERR_TEXTURE_ADDR));
		i++;
	}
	game->frame.buffer = mlx_new_image(game->mlx_init, S_W, S_H);
	if (!game->frame.buffer)
		return (ft_error(game, ERR_FRAME));
	game->frame.addr = (int *)mlx_get_data_addr(game->frame.buffer,
			&(game->frame.bpp),
			&(game->frame.size_line), &(game->frame.endian));
	if (!game->frame.addr)
		return (ft_error(game, ERR_FRAME_ADDR));
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_H)
		return ;
	game->frame.addr[y * (game->frame.size_line / 4) + x] = color;
}

t_img	get_wall_texture(t_game *game, int hit)
{
	game->ray.angle = radiant_angle(game->ray.angle);
	if (hit == 0)
	{
		if (game->ray.angle > M_PI / 2 && game->ray.angle < 3 * (M_PI / 2))
			return (game->img[2]);
		else
			return (game->img[3]);
	}
	else
	{
		if (game->ray.angle > 0 && game->ray.angle < M_PI)
			return (game->img[1]);
		else
			return (game->img[0]);
	}
}
