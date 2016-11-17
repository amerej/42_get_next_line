/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 01:55:22 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/17 22:20:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd		*ft_list_new_fd(int fd)
{
	t_fd	*list;

	list = (t_fd *)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->fd = fd;
	list->next = NULL;
	return (list);
}

void		ft_list_push_back_fd(t_fd **list, t_fd *new)
{
	t_fd	*list_i;

	list_i = *list;
	if (!list_i)
		*list = new;
	else
	{
		while (list_i->next)
			list_i = list_i->next;
		list_i->next = new;
	}
}

void 		print_list_fd(t_fd **list)
{
	t_fd	*list_i;

	list_i = *list;
	if (list_i)
	{
		while (list_i)
		{
			printf("FD%d ", list_i->fd);
			list_i = list_i->next;
		}
	}
	printf("\n");
}

int			get_next_line(int const fd, char **line)
{
	int					count;
	char				buffer[BUFF_SIZE + 1];
	static t_fd			*list;
	t_fd				*list_i;
	int					i;

	list_i = list;
	if (!list_i)
	{
		ft_list_push_back_fd(&list, ft_list_new_fd(fd));
	}
	else
	{
		while (list_i->next && list_i->fd != fd)
			list_i = list_i->next;
		if (list_i->next == NULL)
			ft_list_push_back_fd(&list, ft_list_new_fd(fd));
	}
	print_list_fd(&list);
	return (FALSE);
}

int			main(int argc, char *argv[])
{
	int		count;
	int 	fd_1 = open(argv[1],O_RDONLY);
	int 	fd_2 = open(argv[2],O_RDONLY);
	int 	fd_3 = open(argv[3],O_RDONLY);
	int 	fd_4 = open(argv[4],O_RDONLY);
	int 	fd_5 = open(argv[5],O_RDONLY);
	int 	fd_6 = open(argv[6],O_RDONLY);
	char	*line = NULL;

	get_next_line(fd_4, &line);
	get_next_line(fd_1, &line);
	get_next_line(fd_2, &line);
	get_next_line(fd_1, &line);
	get_next_line(fd_3, &line);
	get_next_line(fd_1, &line);
	get_next_line(fd_1, &line);
	get_next_line(fd_4, &line);
	get_next_line(fd_5, &line);		// Test with not existing file
	get_next_line(fd_6, &line);

	return (FALSE);
}
