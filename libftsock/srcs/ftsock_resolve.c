/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsock_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 19:17:08 by garm              #+#    #+#             */
/*   Updated: 2014/05/20 01:36:43 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsock.h"

static int	is_ipv4(char **ip)
{
	int		i;
	int		num;

	i = 0;
	if (ft_split_len(ip) == 4)
	{
		while (i < 4)
		{
			if (!ft_strisnum(ip[i]))
				return (0);
			num = (int)ft_atoi(ip[i]);
			if (num < 0 || num > 255)
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

void		ftsock_resolve_host(t_tcpsock *host, char *dns)
{
	struct hostent		*he;

	if (!ftsock_is_ipv4_format(dns))
	{
		if ((he = gethostbyname(dns)) == NULL)
			host->error = FTSOCK_UNABLE_RESOLVE;
		else
			ft_memcpy(&(host->sin.sin_addr), he->h_addr_list[0], he->h_length);
	}
	else
		host->sin.sin_addr.s_addr = inet_addr(dns);
}

int			ftsock_is_ipv4_format(char *ip)
{
	int		ipv4;
	char	**split;

	split = ft_strsplit(ip, '.');
	ipv4 = is_ipv4(split);
	ft_split_destroy(split);
	return (ipv4);
}
