/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkless12 <darkless12@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:35:54 by ddiogo-f          #+#    #+#             */
/*   Updated: 2024/11/22 17:50:27 by darkless12       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*trim_end_str(char *str, ssize_t pos);
char	*get_next_line(int fd);
char	*strjoin_gnl(char const *line, char const *buffer, int pos);
ssize_t	strlcat_gnl(char *temp, const char *src, ssize_t size);
ssize_t	strlen_gnl(const char *str);
ssize_t	find_target(char *str);

#endif