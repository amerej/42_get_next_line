/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 01:55:22 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/19 04:38:14 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_fd	*ft_fd_manager(t_fd **list, int fd)
{
	while (*list && (*list)->fd != fd)
		list = &(*list)->next;
	if (!*list)
	{
		*list = (t_fd *)malloc(sizeof(**list));
		(*list)->fd = fd;
		(*list)->next = NULL;
	}
	return (*list);
}

int			get_next_line(int const fd, char **line)
{
	int				count;
	char			buffer[BUFF_SIZE + 1];
	static t_fd		*list = NULL;
	int				i;
	t_fd			*current_fd;

	if (!line || fd == -1)
		return (-1);
	if (*line)
		*line == NULL;
	current_fd = ft_fd_manager(&list, fd);
	printf("current fd = %d - adress = %p\n", current_fd->fd, &(current_fd->fd));
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

	printf(" close: %d ", close(fd_1));

	get_next_line(fd_4, &line);
	get_next_line(fd_1, &line);
	get_next_line(fd_2, &line);
	get_next_line(fd_1, &line);
	get_next_line(fd_3, &line);
	get_next_line(fd_4, &line);
	get_next_line(fd_5, &line);		// Test with not existing file
	get_next_line(fd_6, &line);
	get_next_line(fd_1, &line);
	return (FALSE);
}
