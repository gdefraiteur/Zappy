/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_srv_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:17:59 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 18:02:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ftsock.h"
#include "serveur.h"

static void	print_server(int port)
{
	ft_putstr("Server reachable at port ");
	ft_putnbr(port);
	ft_putchar('\n');
}

void		srv_create(t_env *e, int port)
{
	t_tcpsock	*s;

	s = ftsock_create(FTSOCK_SERVER, port);
	if (port == 0)
		print_server(s->port);
	e->fds[s->sock].type = FD_SERV;
	e->fds[s->sock].fct_read = srv_accept;
	ftsock_destroy(&s);
}
