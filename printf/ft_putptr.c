/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:39:54 by luqli             #+#    #+#             */
/*   Updated: 2023/12/03 19:01:40 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptrhex(unsigned long long ptr)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (ptr < 16)
		len += ft_putchar(base[ptr]);
	else
	{
		len += ft_putptrhex(ptr / 16);
		len += ft_putchar(base[ptr % 16]);
	}
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	len += ft_putptrhex(ptr);
	return (len);
}
