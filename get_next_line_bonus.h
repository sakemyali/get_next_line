/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:44 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/21 20:38:36 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*strjoin_and_free(char *s1_old, char *s2);
char	*ft_strdup_gnl(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*read_core(int fd, char *save, char *buf);
char	*read_letter(int fd, char *save);
char	*extraction_line(char *save);
char	*free_save(char *save_old);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
