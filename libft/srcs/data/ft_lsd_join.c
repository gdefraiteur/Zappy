/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/29 21:07:47 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:07:50 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_lsd_join(t_dlist *lsd1, t_dlist *lsd2)
{
	t_dlist	*ret;

	if (!lsd1 && !lsd2)
		return (NULL);
	lsd1 = ft_lsd_getlast(lsd1);
	lsd2 = ft_lsd_getfirst(lsd2);
	if (!lsd1)
	{
		lsd2->prev = NULL;
		ret = ft_lsd_getfirst(lsd2);
	}
	else if (!lsd2)
	{
		lsd1->next = NULL;
		ret = ft_lsd_getfirst(lsd1);
	}
	else
	{
		lsd1->next = lsd2;
		lsd2->prev = lsd1;
		ret = ft_lsd_getfirst(lsd1);
	}
	return (ret);
}
