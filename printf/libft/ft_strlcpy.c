/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:48 by luqli             #+#    #+#             */
/*   Updated: 2023/11/01 21:03:12 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
	{
		return (ft_strlen(src));
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main()
{
char src[] = "fdvervrev";
char dest[5];

size_t len_ft = ft_strlcpy(dest, src, 0);
size_t len_str = strlcpy(dest, src, 0);

// output
printf("ft_strlcpy - Copied: %s, Length: %zu\n", dest, len_ft);
printf("strlcpy - Copied: %s, Length: %zu\n", dest, len_str);
}*/