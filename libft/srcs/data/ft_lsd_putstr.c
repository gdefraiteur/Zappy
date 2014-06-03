/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 06:36:00 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:03:41 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_output.h"

int		ft_lsd_putstr(t_dlist *elem)
{
	t_dlist	*tmp;

	if (!elem)
	{
		ft_putstr("[NULL]\n");
		return (0);
	}
	tmp = elem;
	ft_putstr((char *)tmp->data);
	while (tmp->next)
	{
		ft_putstr(" <--> ");
		tmp = tmp->next;
		ft_putstr((char *)tmp->data);
	}
	ft_putchar('\n');
	return (1);
}
