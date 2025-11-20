/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:17:50 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/20 19:14:07 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until(int fd, int *end_flag)
{
	ssize_t		bytes;
	char		*temp_buffer;

	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (*end_flag = -1, NULL);
	bytes = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes == 0)
		return (free(temp_buffer), *end_flag = 1, NULL);
	else if (bytes < 0)
		return (free(temp_buffer),*end_flag = -1, NULL);
	temp_buffer[bytes] = '\0';
	return (temp_buffer);
}

static void	clean_buffer(char *buffer, char *line)
{
	ssize_t	newline_idx;
	size_t	i;

	newline_idx = get_newline(line);
	if (newline_idx < 0)
	{
		buffer[0] = '\0';
		return ;
	}
	i = 0;
	while (line[newline_idx + i + 1] && i < BUFFER_SIZE)
	{
		buffer[i] = line[newline_idx + i + 1];
		i++;
	}
	buffer[i] = '\0';
}

static char	*read_line(int fd, char *initial, int *end_flag)
{
	char	*line;
	char	*chunk;

	line = initial;
	while (*end_flag == 0 && line != NULL && get_newline(line) < 0)
	{
		chunk = read_until(fd, end_flag);
		line = ft_strjoin(line, chunk);
		if (!line && *end_flag != 1)
			*end_flag = -1;
	}
	return (line);
}

static char	*extract_line(char *buffer, char *line)
{
	ssize_t	newline_idx;
	char	*result;

	result = line;
	newline_idx = get_newline(line);
	if (newline_idx >= 0)
	{
		clean_buffer(buffer, line);
		result = ft_substr(line, 0, (size_t)newline_idx + 1);
		free(line);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			end_flag;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	if (read(fd, buffer[fd], 0) < 0)
	{
		buffer[fd][0] = '\0';
		return (NULL);
	}
	end_flag = 0;
	if (!buffer[fd][0])
		line = read_until(fd, &end_flag);
	else
		line = ft_strdup(buffer[fd]);
	line = read_line(fd, line, &end_flag);
	if (!line || end_flag < 0)
		return (buffer[fd][0] = '\0', free(line), NULL);
	if (end_flag == 1 && (!line || !line[0]))
		return (buffer[fd][0] = '\0', free(line), NULL);
	return (extract_line(buffer[fd], line));
}
