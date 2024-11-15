/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:17:05 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/27 12:25:34 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	set_player_angle(t_game *game, char t);

int	is_player(char t)
{
	if (t == 'N' || t == 'S' || t == 'W' || t == 'E')
		return (1);
	return (0);
}

void	find_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
			{
				game->map.y = i;
				game->map.x = j;
				game->player.y = i * T_SIZE + T_SIZE / 2;
				game->player.x = j * T_SIZE + T_SIZE / 2;
				set_player_angle(game, map[i][j]);
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	set_player_angle(t_game *game, char t)
{
	if (t == 'N')
		game->player.angle = 3 * M_PI / 2;
	else if (t == 'S')
		game->player.angle = M_PI / 2;
	else if (t == 'W')
		game->player.angle = M_PI;
	else if (t == 'E')
		game->player.angle = 0;
}

char	*ft_strnew(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = '1';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	same_size(t_game *game, char **map, int width)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) < width)
		{
			line = ft_strnew(width - ft_strlen(map[i]));
			if (!line)
				return (ft_error(game, ERR_MALLOC));
			catching_join(game, &map, i, &line);
			free(line);
		}
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}
