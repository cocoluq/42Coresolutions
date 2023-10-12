/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:26:27 by luqli             #+#    #+#             */
/*   Updated: 2023/10/12 11:22:00 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 1;
	n = 0;
	if (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
			{
				s *= -1;
			}
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			n = (str[i] - 48) + (n * 10);
			i++;
		}
		return (n * s);
	}
	
}

/*
#include <stdlib.h>
int main()
{
    printf("%d\n", ft_atoi("+120 66"));
    printf("%d\n", atoi("+120 66"));
    printf("%d\n", ft_atoi("--120 66"));
    printf("%d\n", atoi("--120 66"));
}
*/
