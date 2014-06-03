/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_intsearch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 03:13:34 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:03:03 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int		ft_lsd_intsearch(t_dlist *list, int i)
{
	int		cntr;
	t_dlist	*tmp;

	cntr = 1;
	tmp = list;
	while (tmp)
	{
		if (*(int *)(tmp->data) == i)
			return (cntr);
		cntr++;
		tmp = tmp->next;
	}
	return (0);
}
