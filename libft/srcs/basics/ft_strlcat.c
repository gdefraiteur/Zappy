/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:32:48 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:28:34 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = 0;
	if (dst && src && size > 0)
	{
		while (dst[dstlen] != '\0' && size > dstlen)
			dstlen++;
		while (src[i] != '\0')
		{
			if (i + dstlen + 1 < size)
				dst[i + dstlen] = src[i];
			i++;
		}
		if (src[i] == '\0' && dstlen + i < size - 1)
			dst[i + dstlen] = '\0';
		if (size < dstlen)
			return (i + size);
	}
	if (size == 0)
		return (size + ft_strlen((char*)src));
	return (i + dstlen);
}
