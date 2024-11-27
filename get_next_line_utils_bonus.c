/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:39 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/27 11:13:10 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*strjoin_gnl(char const *line, char const *buffer)
{
	int		size;
	char	*temp;

	size = find_target(line) + find_target(buffer);
	temp = (char *)malloc((size + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[0] = 0;
	strlcat_gnl(temp, line, find_target(line) + 1);
	strlcat_gnl(temp, buffer, size + 1);
	return (temp);
}

size_t	strlcat_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = find_target(dest);
	if (size <= i)
		return (size + find_target(src));
	j = 0;
	while (i < size - 1 && src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (find_target(dest) + find_target(&src[j]));
}

void	clean_buffer(char buffer[BUFFER_SIZE + 1])
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (i <= BUFFER_SIZE)
	{
		if (check == 1)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
			check = 1;
		buffer[i] = '\0';
		i++;
	}
}

size_t	find_target(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != 0)
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*fill_buffer(char buffer[BUFFER_SIZE + 1], int fd, char *line)
{
	int		n_bytes;
	int		len_line;
	char	*temp;

	while (buffer[find_target(buffer) - 1] != '\n')
	{
		len_line = find_target(line);
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == -1 || (n_bytes == 0 && len_line == 0))
		{
			free(line);
			return (NULL);
		}
		if (n_bytes == 0 && len_line > 0)
			return (line);
		buffer[n_bytes] = 0;
		temp = strjoin_gnl(line, buffer);
		if (line)
			free(line);
		line = temp;
	}
	return (line);
}
