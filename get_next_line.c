/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:17:50 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/12 09:57:09 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_file(int fd, char *buffer)
{
	ssize_t	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	return (bytes);
}

ssize_t	check_if_end(char *buffer, ssize_t bytes)
{
	ssize_t	i;

	i = 0;
	if (bytes < BUFFER_SIZE)
		return (i);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
	}
	return (-1);
}

void	*add_buffer_list(t_node *fnode, int fd)
{
	t_list	*list;
	ssize_t	i;
	char	*buffer;
	ssize_t	bytes;
	int		lst_size;

	buffer = (char *)malloc(BUFFER_SIZE);
	bytes = read_file(fd, buffer);
	ft_lstadd_back(fnode->flist, ft_lstnew(buffer, fd));
	i = check_if_end(buffer, bytes);
	if (i > 0)
	{
		lst_size = ft_lstsize(fnode->flist);
		while (lst_size > 0)
		{

		}
	}
}

char	*get_next_line(int fd)
{
	static t_node	**first_node;
	ssize_t			total;
	ssize_t			bytes;

	if (fd < 0)
		return (NULL);
}
