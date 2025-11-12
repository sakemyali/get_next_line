/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:41 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/12 09:03:46 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_if_node(int fd, t_node *fnode)
{
	while (fnode->other_fd)
	{
		if (fnode->other_fd == fd)
			return (1);
		fnode = fnode->other_fd;
	}
	return (0);
}
