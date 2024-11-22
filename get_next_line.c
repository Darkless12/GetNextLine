/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/22 17:50:25 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	ssize_t		pos;
	ssize_t		n_bytes;

	line = NULL;
	pos =  find_target(buffer[fd]);
	printf("1st pos %ld", pos);
	if (buffer[fd][pos] == '\n')
	{
		printf("found \\n %s", buffer);
		temp = strjoin_gnl(line, &buffer[fd][pos], 0);
		printf("temp is %s", temp);
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
		temp = strjoin_gnl(line, buffer[fd], BUFFER_SIZE - pos);
		if (line)
			free(line);
		line = temp;
		pos =  find_target(buffer[fd]);
	}
	return (line);
}
