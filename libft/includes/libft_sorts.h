/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_sorts.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 01:13:14 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:21:23 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_SORTS_H
# define LIBFT_SORTS_H

# include "ft_dlist.h"

/*
** Sorts
*/
t_dlist		*ft_lsd_fusion_intsort(t_dlist *unsorted);
t_dlist		*ft_lsd_fusion_strsort(t_dlist *unsorted);

#endif

