/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_insert_before.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 01:31:07 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:02:54 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_lsd_insert_before(t_dlist *next_elem, t_dlist *new_elem)
{
	t_dlist	*prev_elem;

	if (!next_elem && !new_elem)
		return (NULL);
	else if (!next_elem)
		return (ft_lsd_create(new_elem->data, new_elem->size));
	else if (!new_elem)
		return (next_elem);
	prev_elem = next_elem->prev;
	new_elem->prev = prev_elem;
	new_elem->next = next_elem;
	next_elem->prev = new_elem;
	if (prev_elem && prev_elem->next)
		prev_elem->next = new_elem;
	return (new_elem);
}
