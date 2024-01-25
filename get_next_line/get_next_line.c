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
static int	buff_line(int fd, char *line, char *buff)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 1;
	// null the buffer
	ft_bnull(buff, BUFFER_SIZE + 1);
	// store the line of buffer_size in buffer
	while (i < BUFFER_SIZE && ret != 0)
	{
		ret = read(fd, buff + i, 1);
		if (buff[i] == '\n')
			break ;
		i++;
	}
	// join the nonread line
	while (j < i)
	{
		line[j] = buff[j];
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char	*nonread;
	char 		*buffer;
	char		*readlines;
	int			i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, nonread, 0) < 0)
	{
		free(nonread);
		return (NULL);
	}
	i = 1;
	while (!ft_strchr(nonread, '\n') && i > 0)
	{
		i = buff_line(fd, nonread, buffer);
	}
	free(buffer);
	// get the readlines from nonread
	// clean the read line in nonread
	return (readlines);
}
