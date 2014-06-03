/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:56:05 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:26:58 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memory.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*buf;

	if ((buf = (void*)malloc(n)))
	{
		ft_memcpy(buf, s2, n);
		ft_memcpy(s1, buf, n);
		free(buf);
	}
	return (s1);
}
