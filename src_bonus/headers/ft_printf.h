/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:57:52 by tbarret           #+#    #+#             */
/*   Updated: 2023/11/18 22:18:37 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int nb);
int	ft_printunbr(unsigned int nb);
int	ft_printptr(uintptr_t p);
int	ft_printhex(unsigned int p, char type);
int	ft_printf(const char *str, ...);

#endif