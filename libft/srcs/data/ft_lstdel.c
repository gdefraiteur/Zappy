/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 08:28:52 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:04:47 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst)
	{
		temp = *alst;
		while (temp)
		{
			temp = alst[0]->next;
			ft_lstdelone(alst, del);
			alst[0] = temp;
		}
	}
}
