/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 21:53:02 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:28:28 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if ((ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i++;
			j++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			ret[j] = s2[i];
			i++;
			j++;
		}
		ret[j] = '\0';
		return (ret);
	}
	return (NULL);
}
