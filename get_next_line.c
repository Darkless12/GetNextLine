/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:34:10 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/19 15:09:32 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_target(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i - 1);
}

int	fill_line(char *line, char * temp, int fd)
{
	char	*buffer[BUFFER_SIZE + 1];

	read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	temp = strjoin_gnl(line, buffer);
}

char	*get_next_line(int fd)
{
	static char	*line[128];
	char	*temp;
	int			end_line;

	if (line[fd] != NULL)

	end_line = 0;
	while (end_line = 0)
	{
		end_line = fill_line(line[fd], temp[fd], fd);
	}
	return (line[fd]);
}

int	main_gnl(void)
{
	ssize_t	n_bytes;
	int		fd1;
	int		fd2;
	char	buffer[8];
	char	*result;

	fd1 = open("text_01", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		write(2, "File not found\n", 15);
		return (0);
	}
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	close(fd1);
	close(fd2);
}
