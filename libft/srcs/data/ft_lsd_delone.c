/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 06:16:13 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:02:08 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_memory.h"

void	ft_lsd_delone(t_dlist *elem)
{
	int		solo;

	solo = 0;
	if (elem->prev == NULL && elem->next == NULL)
		solo = 1;
	if (!solo && !elem->prev)
	{
		elem->next->prev = NULL;
		elem->next = NULL;
	}
	else if (!solo && !elem->next)
	{
		elem->prev->next = NULL;
		elem->prev = NULL;
	}
	else if (!solo)
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		elem->next = NULL;
		elem->prev = NULL;
	}
	ft_memdel(&(elem->data));
	ft_memdel((void *)elem);
}
