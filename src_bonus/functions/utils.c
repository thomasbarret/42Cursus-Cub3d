/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:43:10 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/27 11:37:59 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_error(t_game *game, char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(2, &str[i], 1);
			i++;
		}
	}
	free_img(game, game->img);
	if (game->map.content)
		ft_free_tab(game->map.content);
	if (game->frame.buffer)
		mlx_destroy_image(game->mlx_init, game->frame.buffer);
	if (game->mlx_init && game->mlx_win)
		mlx_destroy_window(game->mlx_init, game->mlx_win);
	if (game->mlx_init)
		mlx_destroy_display(game->mlx_init);
	if (game->mlx_init)
		free(game->mlx_init);
	exit(0);
}

void	ft_free_tab(char **r)
{
	int	i;

	i = 0;
	if (!r)
		return ;
	while (r[i])
	{
		free(r[i]);
		i++;
	}
	free(r);
}

void	free_img(t_game *game, t_img *r)
{
	int	i;

	i = 0;
	(void)game;
	while (i < 4)
	{
		if (r[i].buffer)
			mlx_destroy_image(game->mlx_init, r[i].buffer);
		if (r[i].path)
			free(r[i].path);
		i++;
	}
}

char	**copy_tab(char **tab)
{
	int		i;
	char	**r;

	i = 0;
	while (tab[i])
		i++;
	r = malloc(sizeof(char *) * (i + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		r[i] = ft_strdup(tab[i]);
		if (!r[i])
		{
			ft_free_tab(r);
			return (NULL);
		}
		i++;
	}
	r[i] = NULL;
	return (r);
}

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
