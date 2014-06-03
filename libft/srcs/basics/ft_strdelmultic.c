/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelmultic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 06:11:26 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:28:06 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdelmultic(char const *str, char c)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!(ret = malloc(ft_strlen(str) + 1)) || !str)
		return (NULL);
	while (*(str + i))
	{
		ret[j] = str[i];
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			i--;
		}
		j++;
		i++;
	}
	return (ret);
}
