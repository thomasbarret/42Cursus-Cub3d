/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:40:49 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/27 11:33:05 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	ft_itemcount(char const *s, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (!s[i + 1] && s[i] != c))
			l++;
		i++;
	}
	return (l);
}

void	ft_garbage(char **r)
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
	return ;
}

static void	ft_itemplace(char const *s, char c, char **r)
{
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	while (s[++i])
	{
		if (s[i] == c)
			continue ;
		j = i;
		while (s[j] != c && s[j])
			j++;
		r[x] = ft_substr(s, i, (j - i));
		if (!r[x])
		{
			ft_garbage(r);
			return ;
		}
		x++;
		i = j - 1;
	}
}

char	**ft_split(char *s, char c)
{
	char	**r;

	if (!s)
		return (0);
	r = ft_calloc((ft_itemcount(s, c) + 1), sizeof(char *));
	if (!r)
		return (0);
	ft_itemplace(s, c, r);
	free(s);
	return (r);
}
