/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:41:39 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/24 21:00:53 by darkless12       ###   ########.fr       */
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

void	*memcpy_gnl(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src && n > 0)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	find_target(char *str)
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