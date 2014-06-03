/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 06:43:05 by garm              #+#    #+#             */
/*   Updated: 2014/04/14 20:37:03 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HTABLE_H
# define FT_HTABLE_H

# include "ft_btree.h"

# define S_P1 "L0KiPEwowXmGbW1Q8v-sNg1e6GaAcgh4lF9-t5IkqBpr5WYc7AQ7jHOyn3bCUdL4"
# define S_P2 "BhMaCEDJu2Vfs_6SdjZkrTexJY8R0PqOTnHtSyF3Nfi9pVMzIUxolZRzuX2_mKvD"
# define HTABLE_SALT S_P1 S_P2
# define HTABLE_SIZE (256 * 256)

typedef t_btree		t_ht;

t_ht		**ft_htable_create(void);
void		ft_htable_destroy(t_ht **hashtable);
void		ft_htable_setdata(t_ht **hashtable, char *id, void *data);
void		*ft_htable_getdata(t_ht **hashtable, char *id);
int			ft_htable_hash(char *id);

#endif

