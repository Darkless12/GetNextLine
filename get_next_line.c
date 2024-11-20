/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/20 19:08:03 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	find_target(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*fill_line(char *line, int fd)
{
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t n_bytes;
	ssize_t pos;

	pos = strlen_gnl(line);
	while (pos == strlen_gnl(line))
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes != -1)
		{
			buffer[n_bytes] = 0;
			temp = strjoin_gnl(line, buffer);
			free(line);
			line = temp;
			pos = find_target(line);
		}
		else
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[128];
	char		*temp;
	ssize_t		pos;

	if (line[fd] == NULL)
		line[fd] = strjoin_gnl("", "");
	pos =  find_target(line[fd]);
	if (pos < strlen_gnl(line[fd]))
	{
		temp = strjoin_gnl("", &line[fd][pos]);
		free(line[fd]);
		line[fd] = temp;
		return (line[fd]);
	}
	temp = fill_line(line[fd], fd);
	line[fd] = temp;
	return (line[fd]);
}
