/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:17:50 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/19 19:07:30 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_checkread(int fd, char *buffer, char *line, int *b)
{
	ssize_t		r;
	ssize_t		nl;
	char		*sub;

	r = read(fd, buffer, BUFFER_SIZE);
	nl = ft_checknl(buffer);
	if (r <= 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	else
	{
		if (r < BUFFER_SIZE && nl < 0)
			*b = 1;
		if (nl > 0)
		{
			sub = ft_substr(buffer, 0, (nl + 1));
			if (sub == NULL)
				return (NULL);
			return (ft_strjoin(line, sub, 1, buffer));
		}
		else
			return (ft_strjoin(line, buffer, 0, buffer));
	}
}

void	ft_cleanbuffer(char *buffer)
{
	ssize_t	nl;
	size_t	j;

	nl = 0;
	j = 0;
	while (buffer[nl] && buffer[nl] != '\n')
		nl++;
	while (nl + j < BUFFER_SIZE)
	{
		buffer[j] = buffer[nl + j + 1];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = 0;
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	char			*line;
	int				b;
	ssize_t			nl;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buffer[fd], 0) < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	nl = ft_checknl(buffer[fd]);
	if (nl > 0)
		line = ft_strjoin(line, ft_substr(buffer[fd], 0, (nl + 1)), 1,
				buffer[fd]);
	else if (buffer[fd][0] != '\0')
		line = ft_strjoin(line, buffer[fd], 0, buffer[fd]);
	b = 0;
	while (b == 0 && line != NULL && ft_checknl(line) < 0)
		line = ft_checkread(fd, buffer[fd], line, &b);
	return (line);
}
