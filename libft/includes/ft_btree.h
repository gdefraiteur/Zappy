/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 04:37:06 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:13:04 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct			s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	char			*id;
	void			*data;
}						t_btree;

t_btree					*ft_bt_new(char *id, void *data);
void					ft_bt_add(t_btree **root, char *id, void *data);
t_btree					*ft_bt_search(t_btree *root, char *id);
void					ft_bt_destroy(t_btree *root);

#endif

