/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:51:17 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/12 22:16:29 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void		check_tiles(t_game *game, char **file);
static void		flood_fill(t_game *game, char ***map, int y, int x);
static int		count_chars(char **map, char *c);

static int	get_max_width(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	map_condition(t_game *game, char **file)
{
	check_tiles(game, file);
	if (count_chars(file + 6, "NSEW") != 1)
		return (ft_free_tab(file), ft_error(game, ERR_PLAYER));
	game->map.content = copy_tab(file + 6);
	if (!game->map.content)
		return (ft_free_tab(file), ft_error(game, ERR_MALLOC));
	game->map.width = get_max_width(game->map.content);
	game->map.height = count_tab(game->map.content);
	same_size(game, game->map.content, game->map.width);
	find_player(game, game->map.content);
	ft_free_tab(file);
}

static void	check_tiles(t_game *game, char **file)
{
	int		i;
	int		j;
	char	**map[2];

	i = 6;
	if (!file[i])
		return (ft_free_tab(file), ft_error(game, ERR_NO_MAP));
	map[0] = copy_tab(file + 6);
	map[1] = file;
	if (!map[0])
		return (ft_free_tab(file), ft_error(game, ERR_MALLOC));
	while (map[0][i])
	{
		j = 0;
		while (map[0][i][j])
		{
			if (map[0][i][j] == '0' || is_player(map[0][i][j]))
				flood_fill(game, map, i, j);
			j++;
		}
		i++;
	}
	ft_free_tab(map[0]);
}

static void	flood_fill(t_game *game, char ***map, int y, int x)
{
	if (ft_strlen(map[0][y]) <= (size_t)x || y < 0 || x < 0)
		return (ft_free_tab(map[0]), ft_free_tab(map[1]),
			ft_error(game, ERR_MAP_NOT_CLOSED));
	if (map[0][y][x] == '1' || map[0][y][x] == 'X')
		return ;
	if (map[0][y][x] == '0' || is_player(map[0][y][x]))
	{
		map[0][y][x] = 'X';
		flood_fill(game, map, y, x - 1);
		flood_fill(game, map, y, x + 1);
		flood_fill(game, map, y - 1, x);
		flood_fill(game, map, y + 1, x);
	}
	else if (!is_player(map[0][y][x]))
		return (ft_free_tab(map[0]), ft_free_tab(map[1]),
			ft_error(game, ERR_MAP_NOT_CLOSED));
}

static int	count_chars(char **map, char *c)
{
	int	i;
	int	j;
	int	k;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			k = 0;
			while (c[k])
			{
				if (map[i][j] == c[k])
					count++;
				k++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
