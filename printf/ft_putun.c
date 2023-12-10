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

int	ft_putun(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putun(nbr / 10);
		len += ft_putchar(nbr % 10 + '0');
	}
	else
		len += ft_putchar(nbr + '0');
	return (len);
}
