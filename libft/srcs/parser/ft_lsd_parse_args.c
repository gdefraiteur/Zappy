/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsd_parse_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 20:08:53 by garm              #+#    #+#             */
/*   Updated: 2014/03/29 20:47:40 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard_helpers.h"
#include "ft_dlist.h"
#include "ft_char.h"
#include "ft_string.h"

static int		ft_isop(char *opt)
{
	size_t	i;

	i = 0;
	if (ft_strcmp(opt, "--") == 0)
		return (0);
	if (opt[0] == '-' && !(opt[0] == '-' && opt[1] == '\0'))
	{
		i = 1;
		while (ft_isalnum(opt[i]) && opt[i] != '-')
			i++;
		if (ft_strlen(opt) == i)
			return (1);
		else
			return (-1);
	}
	return (2);
}

static t_dlist	*ft_argv_to_lsd(int ac, char **av, t_dlist *o, t_dlist *a)
{
	int		i;
	int		parsing_opts;

	parsing_opts = 1;
	i = 1;
	while (i < ac)
	{
		if (ft_isop(av[i]) != 2 && parsing_opts == 1)
		{
			if (ft_isop(av[i]) == 0)
				parsing_opts = 0;
			o = ft_lsd_stack(o, ft_lsd_create(av[i], ft_strlen(av[i]) + 1));
		}
		else
		{
			parsing_opts = 0;
			a = ft_lsd_stack(a, ft_lsd_create(av[i], ft_strlen(av[i]) + 1));
		}
		i++;
	}
	o = (ft_strcmp(o->data, "--") == 0) ? o : LSD_STACK(o, LSD_CREATE("--", 3));
	return (o);
}

static t_dlist	*ft_lsd_del_duplicate_opts(t_dlist *args)
{
	t_dlist		*comp;

	comp = args;
	if (ft_lsd_getlen(args) > 1)
	{
		while (ft_strcmp(args->data, "--") != 0)
		{
			comp = args->next;
			while (ft_strcmp(comp->data, "--") != 0)
			{
				if (ft_strcmp(args->data, comp->data) == 0)
				{
					comp = comp->prev;
					ft_lsd_delone(comp->next);
				}
				comp = comp->next;
			}
			args = args->next;
		}
	}
	return (ft_lsd_getfirst(args));
}

static t_dlist	*ft_lsd_decompose_opts(t_dlist *args)
{
	char	lsd_data[3];

	lsd_data[0] = '-';
	lsd_data[2] = '\0';
	if (!args)
		return (NULL);
	while ((ft_strcmp(args->data, "--") != 0) && args->next)
	{
		if (ft_strlen(args->data) > 2)
		{
			if ((lsd_data[1] = ft_strpickchar(args->data, 1)) == '-')
				ft_lsd_insert_before(args, ft_lsd_create("---", 4));
			ft_lsd_insert_before(args, ft_lsd_create(lsd_data, 3));
		}
		else
			args = args->next;
	}
	if (ft_strlen(args->data) > 2)
	{
		if ((lsd_data[1] = ft_strpickchar(args->data, 1)) == '-')
			ft_lsd_insert_before(args, ft_lsd_create("---", 4));
		ft_lsd_insert_before(args, ft_lsd_create(lsd_data, 3));
	}
	return (ft_lsd_getfirst(args));
}

t_dlist			*ft_lsd_parse_args(int argc, char **argv)
{
	t_dlist		*args;
	t_dlist		*opts;
	t_dlist		*parsed_args;

	opts = ft_lsd_create("", 1);
	args = ft_lsd_create("", 1);
	if ((ft_argv_to_lsd(argc, argv, opts, args)) == NULL)
		return (NULL);
	opts = opts->next;
	args = args->next;
	ft_lsd_delone(opts->prev);
	if (args)
		ft_lsd_delone(args->prev);
	opts = ft_lsd_decompose_opts(opts);
	parsed_args = ft_lsd_join(opts, args);
	parsed_args = ft_lsd_del_duplicate_opts(parsed_args);
	return (parsed_args);
}
