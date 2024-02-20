/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:59:56 by luqli             #+#    #+#             */
/*   Updated: 2024/02/20 22:24:47 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* store the line of buffer_size in buffer, 
   and join the stash line */
static int	buff_line(int fd, char **line, char *buffer)
{
	int		bytes;

	ft_bnull(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || !buffer)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (bytes == 0)
		return (0);
	if (!*line)
		*line = ft_strjoin(ft_newline(*line), buffer);
	else
		*line = ft_strjoin(*line, buffer);
	return (bytes);
}

/* extract the line from stash */
static char	*extract_line(char *stash)
{
	char	*newline;
	size_t	len;
	size_t	i;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	newline = (char *)malloc(sizeof(char) * (len + 2));
	if (!newline)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		newline[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		newline[i] = stash[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

/* clean the stash and return stash pointing the next line*/
static char	*clean_stash(char *stash)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*buffer;
	char		*readline;
	int			bytes;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash[fd], '\n') && bytes > 0)
		bytes = buff_line(fd, &stash[fd], buffer);
	free(buffer);
	if (bytes < 0)
		return (NULL);
	if (!ft_strlen(stash[fd]))
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	readline = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (readline);
}
