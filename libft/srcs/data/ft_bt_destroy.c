/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 06:01:28 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:56:59 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	ft_bt_destroy(t_btree *root)
{
	if (root)
	{
		if (root->left)
			ft_bt_destroy(root->left);
		if (root->right)
			ft_bt_destroy(root->right);
		free(root);
	}
}
