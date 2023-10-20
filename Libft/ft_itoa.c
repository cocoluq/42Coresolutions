/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:38:47 by luqli             #+#    #+#             */
/*   Updated: 2023/10/20 11:38:47 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int	i;

	str = (char *)malloc(sizeof(char) * (i + 1))
	if (!str)
	{
		return (NULL);
	}
	if (n < 0)
	{
		str[0] = '-';
		ft_itoa(-n);
	}
	else if (n == 0)
	{
		str[0] = '0';
	}
	else
	{
		while (n != 0)
		{
			
		}
	}
	return (str);
}