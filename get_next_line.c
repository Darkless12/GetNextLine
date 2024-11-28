/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/28 10:06:39 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[0] != 0)
	{
		clean_buffer(buffer);
		temp = strjoin_gnl(line, buffer);
		if (line)
			free(line);
		line = temp;
		if (buffer[find_target(buffer - 1)] == '\n')
			return (line);
	}
	line = fill_buffer(buffer, fd, line);
	return (line);
}
