/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_leave.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:24:27 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 17:24:29 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "serveur.h"

void		client_leave(int cs, t_env *e)
{
	close(cs);
	clean_fd(&e->fds[cs]);
}
