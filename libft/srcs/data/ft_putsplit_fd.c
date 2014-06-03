/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsplit_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:22:42 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:05:56 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

void	ft_putsplit_fd(char **split, int fd)
{
	int		i;

	i = 0;
	while (split[i])
	{
		ft_putendl_fd(split[i], fd);
		i++;
	}
	if (!i)
		ft_putendl_fd("(null split)", fd);
}
