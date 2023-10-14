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
	while (dst[c] != '\0')
	{
		c++;
	}
	while (src[i] != '\0' && (c + i) < size)
	{
		dst[c + i] = src[i];
		i++;
	}
	dst[c + i] = '\0';
	return (c + i);
}
/*
#inlcude <string.h>

int main() {
    char dest1[20] = "Hello, ";
    char dest2[20] = "Hello, ";
    char source[] = "world!";
    size_t dest_size = sizeof(dest1);

    printf("Source String: %s\n", source);

    // 使用标准库的 strlcat 函数
    size_t result_std = strcat(dest1, source);

    printf("Standard Library - Modified Destination String: %s\n", dest1);
    printf("Result of strlcat: %zu\n", strlen(result_std));

    // 使用自定义的 ft_strlcat 函数
    size_t result_custom = ft_strlcat(dest2, source, dest_size);

    printf("Custom Function - Modified Destination String: %s\n", dest2);
    printf("Result of ft_strlcat: %zu\n", result_custom);

    // 比较两个函数的结果
    if (strlen(result_std) == result_custom && strcmp(dest1, dest2) == 0) {
        printf("Both functions produced the same output.\n");
    } else {
        printf("There is a difference between the functions' output.\n");
    }

    return 0;
}
*/