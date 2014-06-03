/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 08:13:17 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:57:40 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_htable.h"

void	ft_htable_destroy(t_ht **hashtable)
{
	int		i;

	i = 0;
	while (i < HTABLE_SIZE)
	{
		if (hashtable[i])
			ft_bt_destroy(hashtable[i]);
		i++;
	}
	free(hashtable);
}
