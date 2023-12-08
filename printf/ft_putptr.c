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

static int	length_of_pointer(unsigned long long *ptr)
{
	int	len;

	len = 0;
	while (*ptr)
	{
		*ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = length_of_pointer(&ptr);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += write(1, "0x", 2);
	len += ft_puthex_low(ptr);
	return (len);
}
