/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:56:44 by luqli             #+#    #+#             */
/*   Updated: 2023/12/08 13:56:49 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low(unsigned int nbr)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (nbr < 16)
		len += ft_putchar(base[nbr]);
	else
	{
		len += ft_puthex_low(nbr / 16);
		len += ft_putchar(base[nbr % 16]);
	}
	return (len);
}

/*int	main(void)
{
	ft_puthex_low(42);
	return (0);
}*/