/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_srv_accept.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:45:09 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 16:59:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "serveur.h"
#include "libft.h"

void			srv_accept(t_env *e, int s)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;

	csin_len = sizeof(csin);
	cs = x_int(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
	clean_fd(&e->fds[cs]);
	e->fds[cs].type = FD_CLIENT;
	tmp = ft_itoa(cs);
	e->fds[cs].fr = 0;
	e->fds[cs].fw = 0;
	client_add(cs, e, "BIENVENUE\n");
	e->fds[cs].fct_read = client_unknown;
	e->fds[cs].fct_write = client_write;
}
