/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:17:20 by luqli             #+#    #+#             */
/*   Updated: 2023/12/11 15:17:22 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_bnull(void *s, size_t n)
{
	size_t	i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
	{
		return (NULL);
	}
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
	{
		return (NULL);
	}
	j = ft_strlen(s1) - 1;
	if (!set)
	{
		return (ft_strdup(s1));
	}
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (s1[j] && ft_strchr(set, s1[j]))
	{
		j--;
	}
	str = ft_substr(s1, i, j - i + 1);
	return (str);
}