/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:29:43 by tbarret           #+#    #+#             */
/*   Updated: 2024/05/28 15:27:35 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	*gen_buffer(char *s, int fd)
{
	char	*b;
	int		r;

	r = 1;
	b = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!b)
		return (0);
	while (r != 0 && !ft_strchr(s, '\n'))
	{
		r = read(fd, b, BUFFER_SIZE);
		if (r == -1)
		{
			free(b);
			return (0);
		}
		b[r] = 0;
		s = ft_strjoin(s, b);
	}
	free(b);
	return (s);
}

char	*gen_line(char *s)
{
	int		i;
	char	*r;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	r = (char *)malloc(sizeof(char) * (i + 2));
	if (!r)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		r[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		r[i] = s[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

char	*next_buffer(char *s)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	while (s[i] && s[i] != '\n')
			i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	r = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!r)
		return (0);
	i++;
	j = 0;
	while (s[i])
		r[j++] = s[i++];
	r[j] = '\0';
	free(s);
	return (r);
}

char	*get_next_line(int fd)
{
	static char		*s;
	char			*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s = gen_buffer(s, fd);
	if (!s)
		return (0);
	l = gen_line(s);
	s = next_buffer(s);
	return (l);
}
