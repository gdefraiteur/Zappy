/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:09:02 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:04:32 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstaddtoend(t_list **alst, t_list *newelem)
{
	t_list	*tmp;

	tmp = *alst;
	if (alst && newelem)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newelem;
	}
}
