/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:17:50 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/21 15:54:14 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_chunk(int fd, char *storage, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(storage);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		storage = strjoin_and_free(storage, buffer);
		if (!storage)
			return (NULL);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	return (storage);
}

static char	*fill_storage(int fd, char *storage)
{
	char	*buffer;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(storage, '\n'))
		return (storage);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(storage);
		return (NULL);
	}
	tmp = read_chunk(fd, storage, buffer);
	free(buffer);
	return (tmp);
}

static char	*extract_line(const char *storage)
{
	char	*newline_loc;
	size_t	len;
	char	*out;
	size_t	i;

	if (!storage)
		return (NULL);
	newline_loc = ft_strchr(storage, '\n');
	if (!newline_loc)
		len = ft_strlen(storage);
	else
		len = (size_t)(newline_loc - storage) + 1;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = storage[i];
		i++;
	}
	out[len] = '\0';
	return (out);
}

static char	*trim_storage(char *old_storage)
{
	char	*newline_loc;
	char	*new_storage;

	if (!old_storage)
		return (NULL);
	newline_loc = ft_strchr(old_storage, '\n');
	if (!newline_loc || *(newline_loc + 1) == '\0')
	{
		free(old_storage);
		return (NULL);
	}
	new_storage = ft_strdup_gnl(newline_loc + 1);
	free(old_storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = fill_storage(fd, storage[fd]);
	if (!storage[fd] || storage[fd][0] == '\0')
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = extract_line(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = trim_storage(storage[fd]);
	return (line);
}
