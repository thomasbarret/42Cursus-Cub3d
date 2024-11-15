/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:35:46 by tbarret           #+#    #+#             */
/*   Updated: 2024/06/26 09:16:29 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	n;
	long int	r;

	i = 0;
	n = 1;
	r = 0;
	if (!str || !str[0])
		return (-1);
	while ((str[i] > 7 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	if (i != (int)ft_strlen(str))
		return (-1);
	return (r * n);
}
