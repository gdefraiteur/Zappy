/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 21:07:12 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/09 21:07:13 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						check_team_(t_env *e, int cs, char *tmp2)
{
	if (e->fds[cs].noteam == 1 && e->fds[cs].pl >= -1)
	{
		e->fds[cs].noteam = 0;
		e->fds[cs].team = search_team(tmp2, e, cs);
	}
	return (1);
}

int						get_opt_(char *buf, t_env *e, int cs)
{
	int					i;
	char				*tmp;
	char				*tmp2;

	tmp = (char *)malloc(sizeof(char) * (lenuntil(buf, ' ') + 1));
	if (strchr(buf, '\n') != NULL)
		tmp2 = getuntil_(buf, '\n');
	else
		tmp2 = ft_strclone(buf);
	i = 0;
	while (tmp2[i] != '\0')
	{
		tmp[i] = tmp2[i];
		tmp[i + 1] = '\0';
		if (foundop(tmp, tmp2, e, cs) != -1)
			break ;
		i++;
	}
	check_team_(e, cs, tmp2);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&tmp2);
	if (strchr(buf, '\n') != NULL && buf[lenuntil(buf, '\n') + 1] != '\0')
		return (get_opt_(&buf[lenuntil(buf, '\n') + 1], e, cs));
	return (1);
}
