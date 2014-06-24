/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 13:38:54 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 16:35:45 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int					get_next_line(int fd, char **line)
{
	char			stock;
	int				index;
	int				test;

	stock = '\0';
	index = 0;
	line[0] = (char *)malloc(sizeof(char *) * 150);
	while ((test = read(fd, &stock, 1)) == 1)
	{
		line[0][index] = stock;
		if (stock == '\n')
		{
			line[0][index] = '\0';
			if (ft_strlen(line[0]) == 0)
				return (0);
			return (1);
		}
		index++;
	}
	if (test == -1)
	{
		ft_putstr("WRONG FILE\n");
		exit(0);
	}
	return (0);
}
