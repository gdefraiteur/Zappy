/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 23:30:11 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:30:04 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		j;

	while (*s && ft_iswhitespace(*s))
		s++;
	i = ft_strlen(s) - 1;
	j = 0;
	while (i > 0 && ft_iswhitespace(s[i]))
	{
		j++;
		i--;
	}
	if ((ret = ft_memalloc(ft_strlen(s) - j + 1)))
		return (ft_strncpy(ret, s, ft_strlen(s) - j));
	else
		return (ft_strdup(s));
}
