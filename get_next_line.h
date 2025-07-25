/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiogo-f <ddiogo-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:35:54 by ddiogo-f          #+#    #+#             */
/*   Updated: 2025/03/13 10:56:34 by ddiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*fill_buffer(char buffer[BUFFER_SIZE + 1], int fd, char *line);
char	*get_next_line(int fd);
char	*strjoin_gnl(char const *line, char const *buffer);
size_t	strlcat_gnl(char *temp, const char *src, size_t size);
size_t	find_target(const char *str);
void	clean_buffer(char buffer[BUFFER_SIZE + 1]);

#endif