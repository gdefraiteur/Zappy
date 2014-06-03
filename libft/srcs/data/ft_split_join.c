/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 05:12:54 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:06:31 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_split.h"

char	**ft_split_join(char **split1, char **split2)
{
	char	**ret_split;
	int		i;

	if (split1 && !split2)
		return (ft_split_cpy(split1));
	else if (!split1 && split2)
		return (ft_split_cpy(split2));
	else if (!split1 && !split2)
		return (NULL);
	ret_split = ft_split_cpy(split1);
	i = 0;
	while (split2[i])
	{
		ret_split = ft_split_add(ret_split, split2[i]);
		i++;
	}
	return (ret_split);
}
