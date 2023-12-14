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

char	*get_next_line(int fd)
{
	static char *str;
	char *buf;
	int ret;

	if (!(buf = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	if (!str)
		str = ft_strnew(0);
	while (!ft_strchr(str, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}
