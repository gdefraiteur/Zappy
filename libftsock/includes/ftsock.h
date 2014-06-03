/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsock.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:29:18 by garm              #+#    #+#             */
/*   Updated: 2014/05/22 12:56:21 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSOCK_H
# define FTSOCK_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>

# include "ft_memory.h"
# include "ft_string.h"
# include "ft_split.h"
# include "ft_output.h"

# define SINSIZE sizeof(struct sockaddr_in)

# define FTSOCK_SERVER 0
# define FTSOCK_CLIENT 1

# define FTSOCK_NOERROR 0
# define FTSOCK_SOCKETERROR 1
# define FTSOCK_BINDERROR 2
# define FTSOCK_LISTENERROR 3
# define FTSOCK_ACCEPTERROR 4
# define FTSOCK_CONNECTERROR 5
# define FTSOCK_MUSTBE_CLIENT 6
# define FTSOCK_MUSTBE_SERVER 7
# define FTSOCK_UNABLE_RESOLVE 8
# define FTSOCK_BAD_PORT 9
# define FTSOCK_SETSOCK_ERROR 10

# define FTSOCK_SOCKETERROR_STR "ftsock: socket() error."
# define FTSOCK_BINDERROR_STR "ftsock: bind() error."
# define FTSOCK_LISTENERROR_STR "ftsock: listen() error."
# define FTSOCK_ACCEPTERROR_STR "ftsock: accept() error."
# define FTSOCK_CONNECTERROR_STR "ftsock: connect() error."
# define FTSOCK_MUSTBE_CLIENT_STR "ftsock error: type must be FTSOCK_CLIENT."
# define FTSOCK_MUSTBE_SERVER_STR "ftsock error: type must be FTSOCK_SERVER."
# define FTSOCK_UNABLE_RESOLVE_STR "ftsock error: Unable to resolve host."
# define FTSOCK_BAD_PORT_STR "ftsock error: Bad port."
# define FTSOCK_SETSOCK_ERROR_STR "ftsock error : setsockopt() error."

typedef struct sockaddr		t_sockaddr;
typedef struct protoent		t_protoent;

typedef struct				s_tcpsock
{
	struct sockaddr_in		sin;
	int						sock;
	char					*ip;
	int						port;
	int						backlog;
	char					type;
	char					error;
	void					*data;
}							t_tcpsock;

/*
** ftsock.c
*/
t_tcpsock					*ftsock_create(char type, ...);
void						ftsock_destroy(t_tcpsock **socket);

/*
** ftsock_client.c
*/
t_tcpsock					*ftsock_create_client(char *ip, int port);
void						ftsock_connect(t_tcpsock *s);

/*
** ftsock_server.c
*/
t_tcpsock					*ftsock_create_server(int port, int queue_len);
t_tcpsock					*ftsock_wait(t_tcpsock *serv);

/*
** ftsock_resolve.c
*/
void						ftsock_resolve_host(t_tcpsock *host, char *ip);
int							ftsock_is_ipv4_format(char *ip);

/*
** ftsock_error.c
*/
int							ftsock_perror(char error);

#endif
