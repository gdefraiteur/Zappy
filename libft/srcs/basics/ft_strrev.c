/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 07:37:09 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:29:42 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str)
{
	size_t	i;
	int		j;
	char	*reverse;

	if (!(reverse = ft_memalloc(ft_strlen(str) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 1;
	while (i < ft_strlen(str))
	{
		*(reverse + i) = *(str + (ft_strlen(str) - j));
		i++;
		j++;
	}
	reverse[i] = '\0';
	return (reverse);
}
