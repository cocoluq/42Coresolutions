/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:09:13 by luqli             #+#    #+#             */
/*   Updated: 2023/12/08 16:09:15 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_up(unsigned int nbr)
{
	char	*base;
	int		len;

	base = "0123456789ABCDEF";
	len = 0;
	if (nbr < 16)
		len += ft_putchar(base[nbr]);
	else
	{
		len += ft_puthex_up(nbr / 16);
		len += ft_putchar(base[nbr % 16]);
	}
	return (len);
}

/*int	main(void)
{
	ft_puthex_up(42);
	return (0);
}*/