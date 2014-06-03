/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 05:34:32 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:03:22 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_lsd_push(t_dlist *elem, t_dlist *new_elem)
{
	t_dlist	*first;

	first = ft_lsd_getfirst(elem);
	if (!elem && !new_elem)
		return (NULL);
	else if (!elem)
		return (ft_lsd_create(new_elem->data, new_elem->size));
	else if (!new_elem)
		return (elem);
	new_elem = ft_lsd_create(new_elem->data, new_elem->size);
	new_elem->next = first;
	first->prev = new_elem;
	return (new_elem);
}
