/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:49:08 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/20 17:22:44 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> //O_RDWR

char		*get_next_line(int fd);
ssize_t		get_newline(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(const char *s, size_t start, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);

#endif
