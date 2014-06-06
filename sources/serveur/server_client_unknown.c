/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_unknown.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:18:03 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 17:21:56 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "serveur.h"
#include "libft.h"

void		client_leave(int cs, t_env *e)
{
	close(cs);
	clean_fd(&e->fds[cs]);
}

void		client_unknown(t_env *e, int cs)
{
	int	r;
	int	count;

	count = e->fds[cs].fr;
	r = recv(cs, e->fds[cs].buf_read + count, BUF_SIZE - count, 0);
	x_int(-1, r, "recv");
	if (r <= 0)
		client_leave(cs, e);
	else
	{
		e->fds[cs].fr += r;
		if (!ft_strchr(e->fds[cs].buf_read, '\n') && e->fds[cs].fr != BUF_SIZE)
			return ;
		if (ft_strequ(e->fds[cs].buf_read, "GRAPHIC"))
			e->fds[cs].fct_read = client_graphic;
		else
		{
			e->fds[cs].fct_read = client_player;
			ft_strcpy(e->fds[cs].team, e->fds[cs].buf_read);
		}
		ft_strclr(e->fds[cs].buf_read);
		e->fds[cs].fr = 0;
	}
}
