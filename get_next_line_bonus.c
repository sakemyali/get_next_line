/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:46 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/21 21:21:26 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_until(int fd, char *buffer, char *temp_buffer)
{
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		if (bytes == 0)
			break ;
		temp_buffer[bytes] = '\0';
		buffer = free_strjoin(buffer, temp_buffer);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

static char	*read_line(int fd, char *storage)
{
	char	*temp_buffer;
	char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(storage, '\n'))
		return (storage);
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(storage), NULL);
	res = read_until(fd, storage, temp_buffer);
	return (free(temp_buffer), res);
}

static char	*extract_line(const char *buffer)
{
	char	*newline_addr;
	size_t	len;
	char	*res;
	size_t	i;

	if (!buffer)
		return (NULL);
	newline_addr = ft_strchr(buffer, '\n');
	if (!newline_addr)
		len = ft_strlen(buffer);
	else
		len = (size_t)(newline_addr - buffer) + 1;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = buffer[i];
		i++;
	}
	return (res[len] = '\0', res);
}

static char	*clean_buffer(char *buffer)
{
	char	*newline_addr;
	char	*res;

	if (!buffer)
		return (NULL);
	newline_addr = ft_strchr(buffer, '\n');
	if (!newline_addr || *(newline_addr + 1) == '\0')
		return (free(buffer), NULL);
	res = ft_strdup(newline_addr + 1);
	return (free(buffer), res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = clean_buffer(buffer[fd]);
	return (line);
}
