/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:41 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/21 21:22:10 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_strjoin(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	return (free(s1), res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	i;
	size_t	len;

	if (!str)
	{
		res = (char *)malloc(1);
		if (!res)
			return (NULL);
		return (res[0] = '\0', res);
	}
	len = ft_strlen(str);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	return (res[i] = '\0', res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res[i] = '\0', res);
}

char	*ft_strchr(const char *str, int c)
{
	char	cchar;

	if (!str)
		return (NULL);
	cchar = (char)c;
	while (*str)
	{
		if (*str == cchar)
			return ((char *)str);
		str++;
	}
	if (cchar == '\0')
		return ((char *)str);
	return (NULL);
}
