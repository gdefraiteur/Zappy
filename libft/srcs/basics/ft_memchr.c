/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:35:15 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:26:40 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*ptr;

	i = 0;
	ptr = s;
	if (!s)
		return (NULL);
	while (i < (n - 1) && ptr[i] != '\0' && ptr[i] != (char)c)
		i++;
	if (ptr[i] == c)
		return ((char*)(ptr + i));
	return (NULL);
}
