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

static char	ft_strnew(size_t size)
{
	char *str;

	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size)
		str[size--] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char *readlines;
	char *bufline;
	int bytes;

	if (!(bufline = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, bufline, 0) < 0)
	{
		free(bufline);
		return (NULL);
	}
	if (!readlines)
		readlines = ft_strnew(0);
	while (!ft_strchr(readlines, '\n') && (bytes = read(fd, bufline, BUFFER_SIZE)))
	{
		bufline[bytes] = '\0';
		readlines = ft_strjoin(readlines, bufline);
	}
	free(bufline);
	return (readlines);
}
