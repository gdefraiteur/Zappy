/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpickchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 23:24:18 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:29:32 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strpickchar(char *str, int index)
{
	int		i;
	char	picked_char;

	if (index >= (int)ft_strlen(str) || index < 0)
		return (0);
	picked_char = str[index];
	i = index + 1;
	while (str[i] != '\0')
	{
		str[i - 1] = str[i];
		i++;
	}
	str[i - 1] = '\0';
	return (picked_char);
}
