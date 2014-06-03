/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 22:42:12 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:28:51 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	if ((ret = ft_memalloc(ft_strlen((char*)s))))
	{
		i = 0;
		while (s[i] != '\0')
		{
			ret[i] = (*f)(i, s[i]);
			i++;
		}
		return (ret);
	}
	return (NULL);
}
