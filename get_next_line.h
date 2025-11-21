/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:49:08 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/21 21:24:39 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h> //read
# include <stdlib.h> //malloc, free

char	*free_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);

#endif
