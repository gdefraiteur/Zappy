/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 19:26:06 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:03:49 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_lsd_rev(t_dlist *original)
{
	t_dlist		*rev;

	original = ft_lsd_getlast(original);
	if (!original)
		return (NULL);
	while (original->prev)
	{
		rev = ft_lsd_stack(rev, original);
		original = original->prev;
	}
	rev = ft_lsd_stack(rev, original);
	ft_lsd_del(original);
	return (ft_lsd_getfirst(rev));
}
