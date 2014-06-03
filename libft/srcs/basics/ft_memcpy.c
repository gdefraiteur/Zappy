/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:17:58 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:26:48 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1 && s2)
	{
		((unsigned char*)s1)[i] = ((unsigned char*)s2)[i];
		i++;
	}
	if (!s1 || !s2)
		return (NULL);
	return (s1);
}
