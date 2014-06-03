/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 03:07:21 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:06:19 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"
#include "ft_memory.h"

void	ft_split_del(char ***split, int index)
{
	char	**split2;

	if (!split && !*split && index < ft_split_len(*split))
		return ;
	split2 = *split + index;
	split2[0] = NULL;
	split2++;
	*split = ft_split_join(*split, split2);
	split2 = split2 - index - 1;
	ft_memdel((void **)split2);
}
