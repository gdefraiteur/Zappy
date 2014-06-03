/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 08:07:29 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:57:30 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_htable.h"

t_ht		**ft_htable_create(void)
{
	return ((t_ht **)ft_memalloc(sizeof(t_ht *) * (HTABLE_SIZE)));
}
