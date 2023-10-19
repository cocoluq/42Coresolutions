/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:56:35 by luqli             #+#    #+#             */
/*   Updated: 2023/10/19 16:56:35 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ss;

	i = 0;
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
	{
		return (NULL);
	}
	while (s[i] && i < len)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[len] = '\0';
	return (ss);
}
