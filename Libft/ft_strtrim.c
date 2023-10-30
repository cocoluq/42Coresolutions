/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:08:02 by luqli             #+#    #+#             */
/*   Updated: 2023/10/19 20:08:02 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
