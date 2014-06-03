/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 05:57:06 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:03:58 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_lsd_stack(t_dlist *elem, t_dlist *new_elem)
{
	if (!elem && !new_elem)
		return (NULL);
	else if (!elem)
		return (ft_lsd_create(new_elem->data, new_elem->size));
	else if (!new_elem)
		return (elem);
	new_elem = ft_lsd_create(new_elem->data, new_elem->size);
	elem = ft_lsd_getfirst(elem);
	new_elem->prev = ft_lsd_getlast(elem);
	ft_lsd_getlast(elem)->next = new_elem;
	return (new_elem);
}
