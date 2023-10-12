/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:01:07 by luqli             #+#    #+#             */
/*   Updated: 2023/10/12 15:02:20 by luqli            ###   ########.fr       */
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
	while (src[i] != '\0' && i < size)
	{
		dst[c + i] = src[i];
		i++;
	}
	dst[c + i] = '\0';
	return (c + j);
}
