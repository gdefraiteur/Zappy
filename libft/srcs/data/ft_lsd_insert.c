/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 01:44:43 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:02:48 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_lsd_insert(t_dlist *prev_elem, t_dlist *new_elem)
{
	t_dlist	*next_elem;

	if (!prev_elem && !new_elem)
		return (NULL);
	else if (!prev_elem)
		return (ft_lsd_create(new_elem->data, new_elem->size));
	else if (!new_elem)
		return (prev_elem);
	next_elem = prev_elem->next;
	new_elem->next = next_elem;
	new_elem->prev = prev_elem;
	prev_elem->next = new_elem;
	if (next_elem && next_elem->prev)
		next_elem->prev = new_elem;
	return (new_elem);
}
