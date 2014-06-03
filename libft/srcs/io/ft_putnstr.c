/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 04:45:00 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:50:21 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_putnstr(const char *str, size_t n)
{
	if (str && n > 0)
	{
		write(1, str, n);
		return ((char *)str + n);
	}
	return ((char *)str);
}
