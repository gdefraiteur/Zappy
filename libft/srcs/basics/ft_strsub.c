/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 20:07:35 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:29:53 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	while (start > 0)
	{
		s++;
		start--;
	}
	if ((ret = (char*)malloc(len + 1)))
	{
		ret = ft_strncpy(ret, s, len);
		ret[len] = '\0';
	}
	return (ret);
}
