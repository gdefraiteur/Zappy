/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:46:48 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:25:38 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		ret;
	int		isnegative;

	i = 0;
	ret = 0;
	isnegative = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
	{
		isnegative = 1;
		i++;
	}
	else if (str[0] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	if (isnegative)
		ret = ret * -1;
	return (ret);
}
