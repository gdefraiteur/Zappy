/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 05:58:10 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:57:20 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_btree.h"

t_btree		*ft_bt_search(t_btree *root, char *id)
{
	if (root && *id)
	{
		if (ft_strcmp(root->id, id) > 0)
			return (ft_bt_search(root->left, id));
		if (ft_strcmp(root->id, id) < 0)
			return (ft_bt_search(root->right, id));
		if (ft_strcmp(root->id, id) == 0)
			return (root);
	}
	return (NULL);
}
