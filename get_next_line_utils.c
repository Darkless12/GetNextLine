/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:39 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/26 14:03:30 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*strjoin_gnl(char const *line, char const *buffer, int excess)
{
	int		size;
	char	*temp;

	size = strlen_gnl(line) + strlen_gnl(buffer) + excess;
	temp = (char *)malloc((size + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[0] = 0;
	strlcat_gnl(temp, line, strlen_gnl(line) + 1);
	strlcat_gnl(temp, buffer, size + 1);
	return (temp);
}

size_t	strlcat_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = strlen_gnl(dest);
	if (size <= i)
		return (size + strlen_gnl(src));
	j = 0;
	while (i < size - 1 && src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (strlen_gnl(dest) + strlen_gnl(&src[j]));
}

size_t	strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != 0)
		i++;
	return (i);
}

void clean_buffer(char buffer[BUFFER_SIZE + 1])
{
	int i;
	int	j;
	int check;

	i = 0;
	j =0 ;
	check = 0;
	while(i <= BUFFER_SIZE)
	{
		if(check == 1)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if(buffer[i] == '\n')
			check = 1;
		buffer[i] = '\0';
		i++;
	}
}

size_t	find_target(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		i++;
	}
	return (i);
}