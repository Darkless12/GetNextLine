/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:39 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/21 16:32:04 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*strjoin_gnl(char const *line, char const *buffer)
{
	int		size;
	char	*temp;

	size = strlen_gnl(line) + strlen_gnl(buffer);
	temp = (char *)malloc((size + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[0] = 0;
	strlcat_gnl(temp, line, strlen_gnl(line) + 1);
	strlcat_gnl(temp, buffer, size + 1);
	return (temp);
}

ssize_t	strlcat_gnl(char *dest, const char *src, ssize_t size)
{
	ssize_t	i;
	ssize_t	j;

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

ssize_t	strlen_gnl(const char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*trim_end_str(char *str, ssize_t pos)
{
	ssize_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((pos + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < pos)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

ssize_t	find_target(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}