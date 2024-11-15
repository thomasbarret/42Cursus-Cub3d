/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:23:48 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/27 12:26:21 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	check_line(char *r, char **l)
{
	if (!r || !l || !*l)
		return ;
	if (*l[0] != '\n' || !ft_strstr(r, "\nF") || !ft_strstr(r, "\nC"))
		return ;
	*l = ft_strjoin(*l, " \n");
}

void	catching_join(t_game *game, char ***map, int i, char **line)
{
	(*map)[i] = ft_strjoin((*map)[i], *line);
	if (!(*map)[i])
	{
		free(*line);
		ft_error(game, ERR_MALLOC);
	}
}
