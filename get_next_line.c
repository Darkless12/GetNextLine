/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/26 14:03:28 by ddiogo-f         ###   ########.fr       */
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

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
    	return (NULL);
	line = NULL;
	pos =  find_target(buffer[fd]);
	if (buffer[fd][0] != 0)
	{
		clean_buffer(buffer[fd]);
		pos =  find_target(buffer[fd]);
		temp = strjoin_gnl(line, buffer[fd], pos - BUFFER_SIZE);
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
		{
			free(line);
			return (NULL);
		}
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
