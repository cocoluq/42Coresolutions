/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:33:38 by luqli             #+#    #+#             */
/*   Updated: 2023/10/15 10:33:40 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*pts;
	size_t		i;

	i = 0;
	pts = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!pts)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		pts[i] = s[i];
		i++;
	}
	pts[i] = '\0';
	return (pts);
}
