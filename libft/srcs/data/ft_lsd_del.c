/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 06:32:24 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:02:04 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_lsd_del(t_dlist *elem)
{
	elem = ft_lsd_getfirst(elem);
	while (elem->next)
	{
		elem = elem->next;
		ft_lsd_delone(elem->prev);
	}
	ft_lsd_delone(elem);
}
