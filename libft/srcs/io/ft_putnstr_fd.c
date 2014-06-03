/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 04:45:00 by garm              #+#    #+#             */
/*   Updated: 2014/05/24 09:22:04 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_putnstr_fd(const char *str, size_t n, int fd)
{
	if (str && n > 0)
	{
		write(fd, str, n);
		return ((char *)str + n);
	}
	return ((char *)str);
}
