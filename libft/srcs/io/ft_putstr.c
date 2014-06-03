/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:39:07 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:50:31 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

int		ft_putstr(char const *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		len = ft_strlen((char *)s);
		write(1, s, len);
	}
	else
	{
		len = 6;
		write(1, "(null)", len);
	}
	return (len);
}
