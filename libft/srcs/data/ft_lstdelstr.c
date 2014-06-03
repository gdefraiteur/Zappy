/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 07:52:32 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 21:04:59 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_memory.h"
#include "ft_string.h"

void	ft_lstdelstr(void *content, size_t content_size)
{
	char	*str;

	str = (char*)content;
	if (str && content_size == (ft_strlen(str) + 1))
		ft_memdel(&content);
}
