/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 10:13:11 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:03:31 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_output.h"

int		ft_lsd_putnbr(t_dlist *elem)
{
	t_dlist	*tmp;
	int		*n;

	if (!elem)
	{
		ft_putstr("[NULL]\n");
		return (0);
	}
	tmp = elem;
	n = tmp->data;
	ft_putnbr(*n);
	while (tmp->next)
	{
		ft_putstr(" <--> ");
		tmp = tmp->next;
		n = tmp->data;
		ft_putnbr(*n);
	}
	ft_putchar('\n');
	return (1);
}
