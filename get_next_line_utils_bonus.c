/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:41 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/21 20:39:04 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*strjoin_and_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup_gnl(const char *src)
{
	char	*dup;
	size_t	i;
	size_t	len;

	if (!src)
	{
		dup = malloc(1);
		if (!dup)
			return (NULL);
		dup[0] = '\0';
		return (dup);
	}
	len = ft_strlen(src);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	if (!str)
		return (NULL);
	ch = (char)c;
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}
