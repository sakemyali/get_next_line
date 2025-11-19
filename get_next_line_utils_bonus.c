/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:41 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/19 19:47:15 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_checknl(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int b, char *buffer)
{
	size_t		i;
	size_t		j;
	char		*strmalloc;

	i = 0;
	j = 0;
	strmalloc = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (strmalloc == NULL)
		return (NULL);
	while (s1[i])
	{
		strmalloc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strmalloc[i + j] = s2[j];
		j++;
	}
	strmalloc[i + j] = '\0';
	free(s1);
	if (b == 1)
		free(s2);
	ft_cleanbuffer(buffer);
	return (strmalloc);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t		i;
	char		*strmalloc;

	i = 0;
	strmalloc = (char *)malloc((sizeof(char) * len) + 1);
	if (strmalloc == NULL)
		return (NULL);
	while (s[i] && i < len)
		strmalloc[i++] = s[start++];
	strmalloc[i] = '\0';
	return (strmalloc);
}
