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

static int	buff_line(int fd, char *line, char *buff)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 1;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
	{
		buff[i] = '\0';
		ft_strcpy(line, buff);
		ft_strcpy(buff, &buff[i + 1]);
	}
	else
	{
		ft_strcpy(line, buff);
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == 0)
			return (0);
		buff[ret] = '\0';
	}
	return (1);
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
	i = 1;
	while (!ft_strchr(nonread, '\n') && i > 0)
	{
		i = read(fd, nonread, BUFFER_SIZE);
		// readlines = ft_strjoin(readlines, nonread);
		// if (!readlines)
		// {
		// 	free(nonread);
		// 	free(readlines);
		// 	return (NULL);
		// }
	}
	free(nonread);
	return (readlines);
}
