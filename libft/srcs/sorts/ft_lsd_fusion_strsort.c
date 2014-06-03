/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_fusion_strsort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 10:51:32 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:46:01 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_dlist.h"
#include "ft_string.h"

static int	ft_lsd_sort_lr(t_dlist *unsorted, t_dlist **l, t_dlist **r)
{
	t_dlist		*pivot;

	pivot = unsorted;
	while (unsorted->next != NULL)
	{
		unsorted = unsorted->next;
		if (ft_strcmp(pivot->data, unsorted->data) >= 0)
			*l = ft_lsd_stack(*l, unsorted);
		else if (ft_strcmp(pivot->data, unsorted->data) < 0)
			*r = ft_lsd_stack(*r, unsorted);
	}
	*l = ft_lsd_stack(*l, ft_lsd_create(pivot->data, pivot->size));
	*l = ft_lsd_getfirst(*l);
	*r = ft_lsd_getfirst(*r);
	if (l && !r)
		return (-1);
	else if (*r && !*l)
		return (1);
	else
		return (0);
}

static int	ft_lsd_elems_isdif(t_dlist *elems)
{
	t_dlist	*tmp;

	if (!elems)
		return (0);
	tmp = elems;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->data, elems->data) != 0)
			return (1);
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->data, elems->data) != 0)
		return (1);
	return (0);
}

t_dlist		*ft_lsd_fusion_strsort(t_dlist *unsorted)
{
	t_dlist		*left;
	t_dlist		*right;
	int			result_lr_sort;

	left = NULL;
	right = NULL;
	if (!unsorted)
		return (NULL);
	unsorted = ft_lsd_getfirst(unsorted);
	result_lr_sort = ft_lsd_sort_lr(unsorted, &left, &right);
	if ((ft_lsd_elems_isdif(left)) || (ft_lsd_elems_isdif(right)))
	{
		if (result_lr_sort == -1)
			left = ft_lsd_fusion_strsort(left);
		else if (result_lr_sort == 1)
			right = ft_lsd_fusion_strsort(right);
		else
		{
			left = ft_lsd_fusion_strsort(left);
			right = ft_lsd_fusion_strsort(right);
		}
	}
	return (ft_lsd_join(left, right));
}
