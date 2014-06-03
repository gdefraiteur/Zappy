/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 05:54:55 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:56:52 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_btree.h"

void	ft_bt_add(t_btree **root, char *id, void *data)
{
	if (!*root)
		*root = ft_bt_new(id, data);
	else if (ft_strcmp((*root)->id, id) >= 0)
		ft_bt_add(&(*root)->left, id, data);
	else
		ft_bt_add(&(*root)->right, id, data);
}
