/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 01:55:35 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/16 11:32:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE  64

typedef struct			s_fd
{
	int					fd;
	char				*tmp;
	struct s_fd			*next;
}						t_fd;

int						get_next_line(int const fd, char **line);
int						get_next_line_multi_fd(int const fd, char **line);
#endif
