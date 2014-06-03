/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_getfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 01:27:29 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:02:17 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_lsd_getfirst(t_dlist *elem)
{
	t_dlist	*ret;

	if (!elem)
		return (NULL);
	ret = elem;
	while (ret->prev != NULL)
		ret = ret->prev;
	return (ret);
}
