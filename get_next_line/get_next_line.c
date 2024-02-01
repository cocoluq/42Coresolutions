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

/* store the line of buffer_size in buffer, 
   and join the nonread line */
static int	buff_line(int fd, char *line, char *buffer)
{
	int		i;
	int		ret;
	int		bytes;

	i = 0;
	ret = 1;
	// null the buffer
	ft_bnull(buffer, BUFFER_SIZE + 1);
	// store the line of buffer_size in buffer
	while (i < BUFFER_SIZE && ret != 0)
	{
		ret = read(fd, buffer + i, 1);
		bytes += ret;
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	// join the nonread line
	line = ft_strjoin(line, buffer);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*nonread;
	char 		*buffer;
	char		*readlines;
	int			bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, nonread, 0) < 0)
	{
		free(nonread);
		return (NULL);
	}
	bytes = 1;
	if (!nonread)
		nonread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(nonread, '\n') && bytes > 0)
	{
		bytes = buff_line(fd, nonread, buffer);
	}
	free(buffer);
	// get the readlines from nonread
	// clean the read line stored in nonread
	return (readlines);
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main()
{
	char *ad = "FILE_PATH";
	int fd = open(ad, O_RDONLY);
	printf("%d", fd);
	close(fd);
	return (0);
}
*/
