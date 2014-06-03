/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarray_to_lsd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 18:03:23 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:01:35 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard_helpers.h"
#include "ft_dlist.h"

t_dlist		*ft_intarray_to_lsd(int *array, int len)
{
	t_dlist	*ret;
	int		i;

	if (!array || len < 1)
		return (NULL);
	i = 1;
	ret = ft_lsd_create(&array[0], PTRSIZE);
	while (i < len)
	{
		ret = ft_lsd_stack(ret, ft_lsd_create(array + i, PTRSIZE));
		i++;
	}
	return (ft_lsd_getfirst(ret));
}
