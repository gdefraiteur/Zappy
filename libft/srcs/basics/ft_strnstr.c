/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:23:57 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:29:28 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s2[j] != '\0' && (i + j) < n)
		{
			if (s1[i + j] != s2[j])
				break ;
			j++;
		}
		if (j == ft_strlen((char*)s2))
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
