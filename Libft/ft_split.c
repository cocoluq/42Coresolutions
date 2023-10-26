/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:50:08 by luqli             #+#    #+#             */
/*   Updated: 2023/10/23 12:50:35 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_split_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i])
		{
			i++;
		}
		else if (s[i] == c)
		{
			count++;
			i++;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	*array;
	char	a;
	char	b;
	size_t	i;

	array = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!array)
	{
		return (NULL);
	}

	//find the address of c: strchr
	//copy [0]-[c - 1] into the ar[0]: strcpy
	//copy [c + 1]-['\0'] into ar[1]: strcpy
	//allocate ar
}
