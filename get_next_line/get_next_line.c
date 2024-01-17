/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:15:13 by luqli             #+#    #+#             */
/*   Updated: 2023/12/11 15:16:02 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size)
		str[size--] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*nonread;
	char 		*buffer;
	char		*readlines;
	int			i;

	nonread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!nonread)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, nonread, 0) < 0)
	{
		free(nonread);
		return (NULL);
	}
	if (!readlines)
		readlines = ft_strnew(0);
	while (!ft_strchr(nonread, '\n') && i > 0)
	{
		i = read(fd, nonread, BUFFER_SIZE);
		readlines = ft_strjoin(readlines, nonread);
		if (!readlines)
		{
			free(nonread);
			free(readlines);
			return (NULL);
		}
	}
	free(nonread);
	return (readlines);
}
