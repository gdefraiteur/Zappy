/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 14:36:48 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:06:55 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_split_merge(char **split, char *delimiter)
{
	char	*retstr;
	char	*tmp;
	int		i;

	if (!split)
		return (NULL);
	i = 0;
	retstr = "";
	while (split[i])
	{
		tmp = retstr;
		retstr = ft_strjoin(retstr, split[i]);
		if (i > 0)
			free(tmp);
		tmp = retstr;
		retstr = ft_strjoin(retstr, delimiter);
		free(tmp);
		i++;
	}
	return (ft_strtrim(retstr));
}
