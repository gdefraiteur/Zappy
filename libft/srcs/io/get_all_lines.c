/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:44:39 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:51:31 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_input.h"

static char		*ft_str_expand(char *str, int addlen)
{
	int		oldlen;
	int		newlen;
	char	*newstr;

	if (!str)
		return (NULL);
	oldlen = ft_strlen(str);
	newlen = oldlen + addlen;
	newstr = ft_strnew(newlen + 1);
	newstr = ft_strcpy(newstr, str);
	ft_strdel(&str);
	return (newstr);
}

char			*get_all_lines(int fd)
{
	int		ret;
	char	buffer[BUFF_SIZE];
	char	*input;

	if (fd < 0)
		return (NULL);
	input = (char *)ft_strnew(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (ret == -1)
		{
			ft_strdel(&input);
			return (NULL);
		}
		input = ft_str_expand(input, ret);
		input = ft_strncat(input, buffer, ret);
	}
	return (input);
}
