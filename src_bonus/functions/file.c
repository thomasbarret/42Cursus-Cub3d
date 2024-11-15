/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:45:10 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/27 11:45:39 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static char	**get_file(t_game *game, char *file);
static void	get_texture(t_game *game, char **file, char *type, int i);
static void	get_color(t_game *game, char **file, char *type, int i);
static int	rgb_to_hex(char *r, char *g, char *b);

void	file_condition(t_game *game, char *path)
{
	char	**file;

	if (!ft_strstr(path, ".cub"))
		ft_error(game, ERR_MAP_EXT);
	file = get_file(game, path);
	if (!file)
		ft_error(game, ERR_MAP_EMPTY);
	get_texture(game, file, "NO", 0);
	get_texture(game, file, "SO", 1);
	get_texture(game, file, "WE", 2);
	get_texture(game, file, "EA", 3);
	get_color(game, file, "F", 4);
	get_color(game, file, "C", 5);
	map_condition(game, file);
}

static char	**get_file(t_game *game, char *file)
{
	char	*l;
	char	*r;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(game, ERR_MAP_OPEN);
	r = ft_strdup("");
	while (1)
	{
		l = get_next_line(fd);
		check_line(r, &l);
		if (!l)
			break ;
		r = ft_strjoin(r, l);
		free(l);
	}
	close(fd);
	if (r[0] == '\0' || ft_strlen(r) <= 1)
	{
		free(r);
		free(l);
		ft_error(game, ERR_MAP_EMPTY);
	}
	return (ft_split(r, '\n'));
}

static void	get_texture(t_game *game, char **file, char *type, int i)
{
	if (!file || !file[i])
		return (ft_free_tab(file), ft_error(game, ERR_NO_TEXTURE));
	if (ft_strncmp(file[i], type, 2))
		return (ft_free_tab(file), ft_error(game, ERR_TEXTURE_TYPE));
	if (ft_strlen(file[i]) < 4)
		return (ft_free_tab(file), ft_error(game, ERR_TEXTURE_TYPE));
	game->img[i].path = ft_strdup(file[i] + 3);
}

static void	get_color(t_game *game, char **file, char *type, int i)
{
	char	**rgb;

	if (!file || !file[i])
		return (ft_free_tab(file), ft_error(game, ERR_NO_COLOR));
	if (ft_strncmp(file[i], type, 1))
		return (ft_free_tab(file), ft_error(game, ERR_COLOR_TYPE));
	if (ft_strlen(file[i]) < 3)
		return (ft_free_tab(file), ft_error(game, ERR_COLOR_VALUE));
	rgb = ft_split(ft_strdup(file[i] + 2), ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (ft_free_tab(rgb), ft_free_tab(file),
			ft_error(game, ERR_COLOR_VALUE));
	if (rgb[3] || ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255
		|| ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255
		|| ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
		return (ft_free_tab(rgb),
			ft_free_tab(file), ft_error(game, ERR_COLOR_VALUE));
	if (!ft_strcmp("F", type))
		game->floor_color = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	else if (!ft_strcmp("C", type))
		game->ceiling_color = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	ft_free_tab(rgb);
}

static int	rgb_to_hex(char *r, char *g, char *b)
{
	return (ft_atoi(r) << 16 | ft_atoi(g) << 8 | ft_atoi(b));
}
