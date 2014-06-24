/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:17:06 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:17:08 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*join;

	i = 0;
	n = 0;
	if (!s1 || !s2 || s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc(sizeof(char)
		* (ft_strlen((char *)s1) + ft_strlen((char *)s2)));
	while ((char)s1[i] != '\0')
	{
		join[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[n] != '\0')
	{
		join[i] = (char)s2[n];
		i++;
		n++;
	}
	join[i] = '\0';
	return (join);
}
