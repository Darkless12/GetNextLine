/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/28 10:13:26 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*temp;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != 0)
	{
		clean_buffer(buffer[fd]);
		temp = strjoin_gnl(line, buffer[fd]);
		if (line)
			free(line);
		line = temp;
		if (buffer[fd][find_target(buffer[fd] - 1)] == '\n')
			return (line);
	}
	line = fill_buffer(buffer[fd], fd, line);
	return (line);
}
