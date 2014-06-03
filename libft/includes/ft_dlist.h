/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 01:09:36 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:13:25 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <string.h>

typedef struct		s_dlist
{
	void			*data;
	size_t			size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

/*
** Double linked list
*/
t_dlist				*ft_lsd_create(void *data, size_t size);
t_dlist				*ft_lsd_insert(t_dlist *prev_elem, t_dlist *new_elem);
t_dlist				*ft_lsd_insert_before(t_dlist *next, t_dlist *new_elem);
t_dlist				*ft_lsd_push(t_dlist *elem, t_dlist *new_elem);
t_dlist				*ft_lsd_stack(t_dlist *elem, t_dlist *new_elem);
t_dlist				*ft_lsd_join(t_dlist *lsd1, t_dlist *lsd2);
t_dlist				*ft_lsd_copy(t_dlist *l);

t_dlist				*ft_lsd_rev(t_dlist *original);

void				ft_lsd_delone(t_dlist *elem);
void				ft_lsd_del(t_dlist *elem);

t_dlist				*ft_lsd_getfirst(t_dlist *elem);
t_dlist				*ft_lsd_getlast(t_dlist *elem);
int					ft_lsd_getlen(t_dlist *elem);

int					ft_lsd_strcount(t_dlist *list, char *str);
int					ft_lsd_intsearch(t_dlist *list, int i);

int					ft_lsd_putstr(t_dlist *elem);
int					ft_lsd_putnbr(t_dlist *elem);

/*
** Double Linked list & Array Conversion
*/
t_dlist				*ft_intarray_to_lsd(int *array, int len);

#endif

