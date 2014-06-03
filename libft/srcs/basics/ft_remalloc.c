/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 03:58:01 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:27:06 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memory.h"

void	*ft_remalloc(void *addr, size_t oldsize, size_t newsize)
{
	void	*newaddr;

	if (!addr || newsize < oldsize)
		return (NULL);
	if ((newaddr = malloc(newsize)) == NULL)
		return (NULL);
	newaddr = ft_memcpy(newaddr, addr, oldsize);
	free(addr);
	return (newaddr);
}
