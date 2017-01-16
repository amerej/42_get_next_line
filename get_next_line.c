/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 01:55:22 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/16 11:34:53 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_tmp(char **line, char **buff_tmp)
{
	char	*tmp;
	char	*tmp_buff_tmp;

	if (!(*buff_tmp))
		return (FALSE);
	if ((tmp = ft_strchr((*buff_tmp), '\n')))
	{
		tmp_buff_tmp = *buff_tmp;
		*line = ft_strjoin_free(*line, ft_strsub(tmp_buff_tmp, 0,
			tmp - tmp_buff_tmp), FREE_PTR_1 | FREE_PTR_2);
		(*buff_tmp) = ft_strdup(tmp_buff_tmp + (tmp - tmp_buff_tmp) + 1);
		if (tmp_buff_tmp)
		{
			free(tmp_buff_tmp);
			tmp_buff_tmp = NULL;
		}
		return (TRUE);
	}
	else
		*line = ft_strjoin_free(*line, (*buff_tmp), FREE_PTR_1 | FREE_PTR_2);
	return (FALSE);
}

static int		ft_read_fd(char **line, int fd, char **buff_tmp)
{
	int		count;
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	char	*tmp2;

	while ((count = read(fd, buffer, BUFF_SIZE)))
	{
		if (count == ERROR)
			return (ERROR);
		buffer[count] = '\0';
		if ((tmp = ft_strchr(buffer, '\n')))
		{
			tmp2 = ft_strsub(buffer, 0, tmp - buffer);
			*line = ft_strjoin_free(*line, tmp2, FREE_PTR_1 | FREE_PTR_2);
			(*buff_tmp) = ft_strdup(buffer + (tmp - buffer) + 1);
			return (TRUE);
		}
		else
			*line = ft_strjoin_free(*line, buffer, FREE_PTR_1);
	}
	if (count == 0 && **line == '\0')
		return (FALSE);
	return (TRUE);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buff_tmp = NULL;

	if (!line || fd < 0)
		return (ERROR);
	if(*line)
		*line = NULL;
	*line = ft_strdup("");
	if (ft_read_tmp(line, &buff_tmp))
		return (TRUE);
	return (ft_read_fd(line, fd, &buff_tmp));
}
