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
   and join the stash line */
static int	buff_line(int fd, char **line, char **buffer)
{
	int		bytes;

	// null the buffer
	ft_bnull(buffer, BUFFER_SIZE + 1);
	// store the line of buffer_size in buffer
	bytes = read(fd, *buffer, 1);
	if (bytes < 0)
		return (-1);
	// join the stash line
	*line = ft_strjoin(*line, buffer);
	return (bytes);
}



char	*get_next_line(int fd)
{
	static char	*stash;
	char 		*buffer;
	char		*readlines;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = buff_line(fd, &stash, &buffer);
	}
	free(buffer);
	// get the readlines from stash
	// clean the read line stored in stash but remain the position of the last read ends
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
