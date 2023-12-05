/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:31:43 by luqli             #+#    #+#             */
/*   Updated: 2023/12/04 21:21:48 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	length_of_int(int i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

int	ft_putun(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
	return (length_of_int(nbr));
}