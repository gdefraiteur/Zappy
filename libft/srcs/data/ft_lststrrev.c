/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:41:14 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:05:38 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_list	*ft_lststrrev(t_list *elem)
{
	if (elem)
	{
		elem->content = ft_strrev(elem->content);
		return (elem);
	}
	return (NULL);
}
