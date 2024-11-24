/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/24 21:03:16 by darkless12       ###   ########.fr       */
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
		memcpy_gnl(buffer[fd], &buffer[fd][pos], BUFFER_SIZE - pos);
		buffer[fd][BUFFER_SIZE - pos] = 0;
		pos =  find_target(buffer[fd]);
		temp = strjoin_gnl(line, buffer[fd], (pos - BUFFER_SIZE) * -1);
		if (line)
			free(line);
		line = temp;
	}
	while (buffer[fd][pos] == '\0')
	{
		n_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (n_bytes == -1)
			return (NULL);
		if (n_bytes == 0 && line)
			return (line);
		buffer[fd][n_bytes] = 0;
		pos =  find_target(buffer[fd]);
		temp = strjoin_gnl(line, buffer[fd], pos - n_bytes);
		if (line)
			free(line);
		line = temp;
	}
	return (line);
}
