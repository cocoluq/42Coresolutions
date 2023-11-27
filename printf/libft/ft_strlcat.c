/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:01:07 by luqli             #+#    #+#             */
/*   Updated: 2023/10/14 15:46:20 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (dst[c] != '\0' && c < size)
	{
		c++;
	}
	while (src[i] != '\0' && (c + i + 1) < size)
	{
		dst[c + i] = src[i];
		i++;
	}
	if (c < size)
	{
		dst[c + i] = '\0';
	}
	return (c + ft_strlen(src));
}

/*#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main(void) {
    char dest[20] = "Hello, ";
    const char *source = "world!";
    size_t size = sizeof(dest);

    // ft_strlcat
    size_t result_ft = ft_strlcat(dest, source, size);
    printf("ft_strlcat: %s, length: %zu\n", dest, result_ft);

    char dest2[20] = "Hello, ";
    const char *source2 = "world!";
    size_t size2 = sizeof(dest2);

    // strlcat
    size_t result_sys = strlcat(dest2, source2, size2);
    printf("strlcat: %s, length: %zu\n", dest2, result_sys);

    // Compare results
    if (result_ft == result_sys && strcmp(dest, dest2) == 0) {
        printf("Both functions produced the same result.\n");
    } else {
        printf("Functions produced different results.\n");
    }

    return 0;
}*/