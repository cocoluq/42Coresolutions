/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:23:15 by luqli             #+#    #+#             */
/*   Updated: 2023/11/27 14:23:17 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long long ptr);
int	ft_putnbr(int nbr);
int	ft_putun(unsigned int nbr);
int	ft_puthex_low(unsigned int nbr);
int	ft_puthex_up(unsigned int nbr);

#endif
