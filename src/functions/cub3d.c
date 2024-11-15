/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:25:55 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/10 15:19:52 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	game_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx_init,
		game->mlx_win, game->frame.buffer, 0, 0);
	mouvement(game);
	ray(game);
	return (0);
}

static int	key_press(int key, t_game *game)
{
	if (key == KEY_RIGHT)
		game->player.r = 1;
	else if (key == KEY_LEFT)
		game->player.r = -1;
	if (key == KEY_A)
		game->player.l_or_r = -1;
	else if (key == KEY_D)
		game->player.l_or_r = 1;
	else if (key == KEY_S)
		game->player.f_or_b = -1;
	else if (key == KEY_W)
		game->player.f_or_b = 1;
	else if (key == KEY_ESC)
		ft_error(game, NULL);
	return (0);
}

static int	key_release(int key, t_game *game)
{
	(void)key;
	game->player.r = 0;
	game->player.l_or_r = 0;
	game->player.f_or_b = 0;
	return (0);
}

static int	close_window(t_game *game)
{
	ft_error(game, NULL);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		ft_error(&game, ERR_NO_MAP);
	file_condition(&game, argv[1]);
	game.mlx_init = mlx_init();
	if (!game.mlx_init)
		ft_error(&game, ERR_MLX_INIT);
	init_img(&game);
	game.mlx_win = mlx_new_window(game.mlx_init, S_W, S_H, "cub3D");
	if (!game.mlx_win)
		ft_error(&game, ERR_MLX_WIN);
	game.player.fov = (FOV * M_PI) / 180;
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, &key_press, &game);
	mlx_hook(game.mlx_win, KeyRelease, KeyReleaseMask, &key_release, &game);
	mlx_hook(game.mlx_win, 17, 0, &close_window, &game);
	mlx_loop_hook(game.mlx_init, &game_loop, &game);
	mlx_loop(game.mlx_init);
	return (0);
}
