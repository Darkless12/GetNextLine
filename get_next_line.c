/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/21 16:32:01 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	ssize_t		pos;
	int			n_bytes;

	line = NULL;
	pos =  find_target(buffer[fd]);
	while (pos == BUFFER_SIZE)
	{
		n_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (n_bytes == -1)
			return (NULL);
		if (n_bytes == 0 && line)
			return (line);
		buffer[fd][n_bytes] = 0;
		temp = strjoin_gnl(line, buffer[fd]);
		free(line);
		line = temp;
		pos =  find_target(buffer[fd]);
	}
	return (line);
}
