/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 04:11:45 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:28:13 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisnum(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && !ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		if (i != 0 && (!ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}
