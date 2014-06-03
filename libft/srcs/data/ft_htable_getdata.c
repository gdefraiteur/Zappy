/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable_getdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 15:14:43 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:57:50 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_htable.h"

void	*ft_htable_getdata(t_ht **hashtable, char *id)
{
	int			hash;
	t_btree		*search;

	hash = ft_htable_hash(id);
	if (hashtable[hash])
	{
		search = ft_bt_search(hashtable[hash], id);
		if (search)
			return (search->data);
		else
			return (NULL);
	}
	else
		return (NULL);
}
