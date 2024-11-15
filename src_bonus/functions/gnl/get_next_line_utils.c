/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:48:09 by tbarret           #+#    #+#             */
/*   Updated: 2024/05/28 15:27:35 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c % 128)
			return ((char *)&s[i]);
		i++;
	}
	if (c % 128 == 0)
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	d = (char *)malloc(sizeof(*s1) * i + 1);
	if (!d)
		return (0);
	while (j < i)
	{
		d[j] = s1[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}

static char	*ft_join(char *r, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		r[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		r[j] = s2[i];
		i++;
		j++;
	}
	r[j] = '\0';
	return (r);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l;
	char	*r;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	l = ft_strlen(s1) + ft_strlen(s2);
	r = (char *)malloc(sizeof(char) * l + 1);
	if (!r)
		return (0);
	r = ft_join(r, s1, s2);
	free(s1);
	return (r);
}
