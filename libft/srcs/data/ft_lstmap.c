/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:50:30 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:05:24 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*i;
	t_list	*ret;

	if (lst)
	{
		i = lst;
		ret = ft_lstnew((void const *)1, 4);
		while (i)
		{
			ft_lstaddtoend(&ret, (*f)(ft_lstnew(i->content, i->content_size)));
			i = i->next;
		}
		i = ret;
		ret = ret->next;
		ft_lstdelone(&i, ft_lstdonothing);
		return (ret);
	}
	else
		return (NULL);
}
