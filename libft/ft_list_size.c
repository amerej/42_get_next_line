/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:12:21 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/10 14:13:00 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *list)
{
	int		count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
