/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_getlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 01:35:52 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:02:39 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int		ft_lsd_getlen(t_dlist *elem)
{
	int		i;
	t_dlist	*tmp;

	i = 0;
	tmp = ft_lsd_getfirst(elem);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
