/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 12:18:31 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 14:38:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "serveur.h"

void	client_add(int cs, t_env *e, char *msg)
{
	int	fill;
	int	len;

	fill = e->fds[cs].fw;
	len = ft_strlen(msg);
	if (len + fill < BUF_SIZE)
	{
		e->fds[cs].fw += len;
		ft_strcpy(e->fds[cs].buf_write + fill, msg);
	}
}
