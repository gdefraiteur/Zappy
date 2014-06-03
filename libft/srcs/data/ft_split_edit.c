/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_edit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 05:08:51 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:06:25 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

char	**ft_split_edit(char **split, char *str, int index)
{
	if (index < ft_split_len(split))
		split[index] = str;
	return (split);
}
