/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htable_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 15:25:17 by garm              #+#    #+#             */
/*   Updated: 2014/04/14 20:36:44 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_htable.h"

int		ft_htable_hash(char *id)
{
	int						i;
	int						j;
	int						size_id;
	unsigned long			ret;
	char					*salt;

	salt = HTABLE_SALT;
	i = 0;
	j = 0;
	ret = 0;
	size_id = (int)ft_strlen(id);
	while (i < size_id)
	{
		if (i == HTABLE_SIZE)
			i = 0;
		if (id[j] == '\0')
			break ;
		ret = ret + (salt[i] ^ id[j]) * ((i * 4) - (j + 4242));
		j++;
		i++;
	}
	ret = ret % (HTABLE_SIZE);
	return ((int)ret);
}
