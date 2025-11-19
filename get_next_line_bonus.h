/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:44 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/19 19:10:11 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
ssize_t		ft_checknl(char *str);
char		*ft_checkread(int fd, char *buffer, char *line, int *b);
void		ft_cleanbuffer(char *buffer);
char		*ft_strjoin(char *s1, char *s2, int b, char *buffer);
char		*ft_substr(char *s, size_t start, size_t len);
void		ft_strcpy(char *dst, char *src);
size_t		ft_strlen(char *s);

#endif
