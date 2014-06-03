/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 09:15:15 by garm              #+#    #+#             */
/*   Updated: 2014/05/24 12:35:39 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_string.h"
#include "ft_output.h"

int			ft_fprintf(int fd, const char *format, ...)
{
	int			offset;
	int			len;
	va_list		ap;

	len = 0;
	va_start(ap, format);
	while ((offset = ft_findc(format, '%')) != -1)
	{
		format = ft_putnstr_fd(format, offset, fd);
		len += offset;
		if (format[0] == '%' && format[1] == '%')
			len += ft_putchar_fd('%', fd);
		else if (format[0] == '%' && format[1] == 's')
			len += ft_putstr_fd(va_arg(ap, char *), fd);
		else if (format[0] == '%' && (format[1] == 'i' || format[1] == 'd'))
			len += ft_putstr_fd(ft_itoa(va_arg(ap, int)), fd);
		else if (format[0] == '%' && format[1] == 'c')
			len += ft_putchar_fd(va_arg(ap, int), fd);
		else
			return (len);
		format = format + 2;
	}
	len += ft_putstr_fd(format, fd);
	va_end(ap);
	return (len);
}
