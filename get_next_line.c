/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/18 16:21:48 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*get_next_line(int fd)
{
	static char	*line[128];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		n_bytes;

	n_bytes = read(fd, buffer, BUFFER_SIZE);
	if (n_bytes == -1)
		write(2, "Cannot read file.\n", 18);
	buffer[BUFFER_SIZE] = 0;
}

int	ft_file_open(void)
{
	ssize_t	n_bytes;
	int		fd;
	char	buffer[8];

	fd = open("text_01", O_RDONLY);
	if (fd == -1)
		write(2, "File not found\n", 15);
	else
	{
		get_next_line(fd);
	}
	close(fd);
}
