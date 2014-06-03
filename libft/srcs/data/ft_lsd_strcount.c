/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_strcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 15:48:47 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:04:08 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_string.h"

int		ft_lsd_strcount(t_dlist *list, char *str)
{
	int			count;
	t_dlist		*tmp;

	tmp = list;
	count = 0;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->data) == 0)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
