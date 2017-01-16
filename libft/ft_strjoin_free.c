/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:36:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/13 17:25:43 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_ptr_strjoin(void *s1, void *s2, char mask)
{
	if (mask & FREE_PTR_1)
	{
		free(s1);
		s1 = NULL;
	}
	if (mask & FREE_PTR_2)
	{
		free(s2);
		s2 = NULL;
	}
	if (mask & (FREE_PTR_1 | FREE_PTR_2))
	{
		free(s1);
		s1 = NULL;
		free(s2);
		s2 = NULL;
	}
}

char	*ft_strjoin_free(char const *s1, char const *s2, char mask)
{
	char	*ret;

	if (!((s1 && s2) && (ret = ft_strnew((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	ft_strcat(ft_strcpy(ret, s1), s2);
	ft_free_ptr_strjoin((void *)s1, (void *)s2, mask);
	return (ret);
}
