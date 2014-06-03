/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:57:12 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:26:43 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				diff;
	unsigned char	ptr1;
	unsigned char	ptr2;

	i = 0;
	diff = 0;
	if (!s1)
		ptr1 = 0;
	if (!s2)
		ptr2 = 0;
	while (i < n && !diff)
	{
		ptr1 = ((unsigned char*)s1)[i];
		ptr2 = ((unsigned char*)s2)[i];
		diff = (int)(ptr1 - ptr2);
		i++;
	}
	return (diff);
}
