/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:11:50 by luqli             #+#    #+#             */
/*   Updated: 2023/10/12 13:18:40 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	
	i = 0;
	c = 0;
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && len > i)
	{
		c = 0;
		while (big[i + c] != '\0' && big[i + c] == little[c] && len > i + c)
		{
			c++;
		}
		if (little[c] == '\0')
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
int main()
{
	const char str[] = "abcDEFghijklmDEFnopqrstuvwxyz";
	const char fnd[] = "DEF";
	size_t ll= 12;
	printf("%s\n", ft_strnstr(str, fnd, ll));
	printf("%s\n", strnstr(str, fnd, ll));
}
*/
