/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 01:09:07 by garm              #+#    #+#             */
/*   Updated: 2014/05/14 01:13:38 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_split_destroy(char	**split)
{
	int		i;

	i = 0;
	if (split)
	{
		while (split[i])
			free((void *)split[i++]);
		free((void *)split);
	}
}
