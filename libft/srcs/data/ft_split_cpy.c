/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:02:35 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:06:08 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard_helpers.h"
#include "ft_memory.h"
#include "ft_string.h"

char	**ft_split_cpy(char **split)
{
	char	**ret_split;
	int		nstr;
	int		i;

	nstr = 0;
	while (split[nstr])
		nstr++;
	ret_split = (char **)ft_memalloc((nstr + 1) * PTRSIZE);
	nstr = 0;
	while (split[nstr])
	{
		ret_split[nstr] = (char *)ft_memalloc(ft_strlen(split[nstr]) + 1);
		i = 0;
		while (split[nstr][i])
		{
			ret_split[nstr][i] = split[nstr][i];
			i++;
		}
		nstr++;
	}
	return (ret_split);
}
