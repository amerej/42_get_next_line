/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 01:55:35 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/18 23:55:19 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

#include <stdio.h>

# define BUFF_SIZE 5

typedef struct			s_fd
{
	int					fd;
	char				*tmp;
	struct s_fd			*next;
}						t_fd;

t_fd		*ft_list_new_fd(int fd);
void		ft_list_push_back_fd(t_fd **list, int fd);
void 		print_list_fd(t_fd **list);
int			get_next_line(int const fd, char **line);
#endif
