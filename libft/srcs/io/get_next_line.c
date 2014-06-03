/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 01:12:59 by garm              #+#    #+#             */
/*   Updated: 2014/05/15 00:04:06 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_basics.h"
#include "get_next_line.h"

static char		*ft_str_expand(char *str, int addlen)
{
	int		oldlen;
	int		newlen;
	char	*newstr;

	if (!str)
		return (NULL);
	oldlen = ft_strlen(str);
	newlen = oldlen + addlen;
	newstr = ft_strnew(newlen + 1);
	newstr = ft_strcpy(newstr, str);
	ft_strdel(&str);
	return (newstr);
}

void			ft_gnl_cut(char *ref, char **s1, char **s2)
{
	int		size1;
	int		size2;

	size1 = ft_strlenc(ref, '\n');
	size2 = ft_ban_neg(ft_strlen(ref) - size1 - 1);
	*s1 = ft_strsub(ref, 0, size1);
	*s2 = ft_strsub(ref, size1 + 1, size2);
	ft_strdel(&ref);
}

static t_gnl	*ft_gnl_addfd(int const fd, t_gnl *fdlist)
{
	t_gnl	*newfd;

	newfd = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	newfd->fd = fd;
	newfd->next = fdlist;
	newfd->memory = (char *)ft_memalloc(1);
	return (newfd);
}

static t_gnl	*ft_gnl_init(int const fd, t_gnl *fdlist)
{
	t_gnl	*cursor;
	t_gnl	*tmp;

	cursor = fdlist;
	if (fd == CLEAN)
	{
		while (cursor)
		{
			ft_strdel(&(cursor->memory));
			tmp = cursor;
			cursor = cursor->next;
			ft_memdel((void **)&tmp);
		}
		return (NULL);
	}
	while (cursor)
	{
		if (cursor->fd == fd)
			return (cursor);
		cursor = cursor->next;
	}
	return (ft_gnl_addfd(fd, fdlist));
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUF];
	static t_gnl	*fdlist = NULL;
	char			**memory;
	int				ret;

	if (fd == CLEAN && line == THIS_CRAP)
	{
		fdlist = ft_gnl_init(CLEAN, fdlist);
		return (0);
	}
	if (fd < 0)
		return (-1);
	fdlist = ft_gnl_init(fd, fdlist);
	memory = &(fdlist->memory);
	while (!(ret = COUNTC(*memory, '\n')) &&
			(ret = read(fd, buf, BUF)) > 0)
	{
		*memory = ft_str_expand(*memory, ret);
		*memory = ft_strncat(*memory, buf, ret);
	}
	if ((ret == -1) || (ret == 0 && **memory == '\0'))
		return (ret);
	ft_gnl_cut(*memory, line, memory);
	return (1);
}
