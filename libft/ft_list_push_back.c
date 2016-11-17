/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:13:54 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/10 14:09:14 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, t_list *elem)
{
	t_list	*list;

	list = *begin_list;
	if (!list)
	{
		list = elem;
		*begin_list = list;
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
}
