/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable_setdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 15:01:58 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:01:27 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include "ft_htable.h"

void	ft_htable_setdata(t_ht **hashtable, char *id, void *data)
{
	int			hash;
	t_btree		*search;

	hash = ft_htable_hash(id);
	if (hashtable[hash])
	{
		search = ft_bt_search(hashtable[hash], id);
		if (search)
			search->data = data;
		else
			ft_bt_add(&hashtable[hash], id, data);
	}
	else
		ft_bt_add(&hashtable[hash], id, data);
}
