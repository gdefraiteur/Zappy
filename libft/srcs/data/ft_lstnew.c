/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 06:48:59 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:05:30 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_memory.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!content)
		content_size = 0;
	if (!(newlist = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content_size)
		newlist->content = (void *)content;
	else
		newlist->content = NULL;
	newlist->content_size = content_size;
	newlist->next = NULL;
	return (newlist);
}
