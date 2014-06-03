/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_getlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 01:31:24 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:02:22 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_lsd_getlast(t_dlist *elem)
{
	t_dlist	*ret;

	if (!elem)
		return (NULL);
	ret = elem;
	while (ret->next)
		ret = ret->next;
	return (ret);
}
