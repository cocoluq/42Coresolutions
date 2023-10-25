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

static int	length_of_int(int i)
{
	int	len;

	len = 0;
	if (i < 0)
	{
		len += 1;
	}
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = length_of_int(n);
	str = (char *)malloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
	{
		str[0] = '0';
	}
	while (n != 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num = -12345;
    char *result = ft_itoa(num);
    if (result)
    {
        printf("Integer: %d\n", num);
        printf("String: %s\n", result);
        free(result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
}
*/
