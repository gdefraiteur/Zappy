/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstrmemdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 16:58:37 by gdefrait          #+#    #+#             */
/*   Updated: 2014/04/27 16:58:39 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sstrmemdel(void ***todel)
{
	int	i;

	i = 0;
	while (todel[0][i] != '\0')
		i++;
	while (i > 0)
	{
		free(todel[0][i]);
		todel[0][i] = NULL;
		i--;
	}
	free(todel);
	todel = NULL;
	return ;
}
