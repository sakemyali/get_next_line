/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:17:53 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/12 08:58:57 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h> //malloc, free
# include <unistd.h> //read
# include <limits.h> //SIZE_MAX
# include <stdint.h> // SIZE_MAX

# define CHUNK_SIZE 50

typedef struct s_list
{
	int				my_fd;
	struct s_list	*other_fd;
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct fnode
{
	int				my_fd;
	struct fnode	*other_fd;
	struct s_list	**flist;
}	t_node;

char	*get_next_line(int fd);
t_list	*ft_lstnew(void *content, int fd);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		check_if_node(int fd, t_node *fnode);
int		ft_lstsize(t_list *lst);


#endif
