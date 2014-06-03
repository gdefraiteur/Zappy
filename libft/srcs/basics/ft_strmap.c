/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:34:27 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:28:46 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	if ((ret = ft_memalloc(ft_strlen((char*)s))))
	{
		i = 0;
		while (s[i] != '\0')
		{
			ret[i] = (*f)(s[i]);
			i++;
		}
		return (ret);
	}
	return (NULL);
}
