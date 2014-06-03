/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 04:49:40 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:57:10 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree		*ft_bt_new(char *id, void *data)
{
	t_btree		*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	node->right = NULL;
	node->left = NULL;
	node->id = id;
	node->data = data;
	return (node);
}
