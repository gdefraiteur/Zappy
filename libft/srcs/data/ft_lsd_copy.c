/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 03:14:14 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:01:46 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard_helpers.h"
#include "ft_dlist.h"

t_dlist		*ft_lsd_copy(t_dlist *l)
{
	t_dlist		*newl;
	t_dlist		*tmp;

	tmp = l;
	while (tmp)
	{
		newl = LSD_STACK(newl, LSD_CREATE(tmp->data, tmp->size));
		tmp = tmp->next;
	}
	return (ft_lsd_getfirst(newl));
}
