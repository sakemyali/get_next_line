/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:17:48 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/20 17:22:50 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char		*dest;
	size_t		i;
	size_t		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dest = (char *) malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

ssize_t	get_newline(char *str)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char		*subs;
	size_t		i;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	subs = (char *)malloc(len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		str = ft_strdup(s2);
		return (free(s2), str);
	}
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (free(s2), NULL);
	i = 0;
	while (i++ < len1)
		str[i - 1] = s1[i - 1];
	while (i++ < len1 + len2)
		str[i - 1] = s2[i - 1 - len1];
	return (str[len1 + len2] = '\0', free(s1), free(s2), str);
}
