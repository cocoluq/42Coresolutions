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

char *ft_strnew(size_t size)
{
    char *str;

    str = (char *)malloc(size + 1);
    if (str == NULL)
        return (NULL);
    memset(str, 0, size + 1);
    return (str);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t i, j;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    str = ft_strnew(strlen(s1) + strlen(s2));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

char	*get_next_line(int fd)
{
	static char *str;
	char *buf;
	int ret;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	if (!str)
		str = ft_strnew(0);
	while (!ft_strchr(str, '\n') && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}
