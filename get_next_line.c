/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/25 15:59:58 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int		pos;
	int		n_bytes;

	line = NULL;
	pos =  find_target(buffer[fd]);
	if (buffer[fd][0] != 0)
	{
		memcpy_gnl(buffer[fd], &buffer[fd][pos + 1], BUFFER_SIZE - (pos + 1));
		buffer[fd][BUFFER_SIZE - (pos + 1)] = '\0';
		pos =  find_target(buffer[fd]);
		temp = strjoin_gnl(line, buffer[fd], pos + 1);
		if (line)
			free(line);
		line = temp;
		if (buffer[fd][pos] == '\n')
			return (line);
	}
	while (buffer[fd][pos] != '\n')
	{
		n_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (n_bytes == -1 || (n_bytes == 0 && strlen_gnl(line) == 0))
			return (NULL);
		if (n_bytes == 0 && strlen_gnl(line) > 0)
			return (line);
		buffer[fd][n_bytes] = 0;
		pos =  find_target(buffer[fd]);
		if (buffer[fd][pos] == '\n')
			pos++;
		temp = strjoin_gnl(line, buffer[fd], pos - n_bytes);
		if (line)
			free(line);
		line = temp;
		pos =  find_target(buffer[fd]);
	}
	return (line);
}
