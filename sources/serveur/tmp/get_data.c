/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 12:40:55 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/21 12:40:56 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


struct s_alpha		*get_data(char *file)
{
	int		fd;
	int		end;
	char	**buf;
	struct s_alpha	*objects;

	end = 0;
	buf = get_file(file);
	while (buf[i] != '\0')
	{
		while (buf[i][j] != '\0' && buf[i][j] == '\t'
			|| buf[i][j] == ' ')
			j++;
		if (buf[i][j] == '+')
		{
			i = get_values(objects, &buf[i][j], &buf[i + 1]);
		}
	}
}

t_is				ft_is(char *what, void *data)
{
	t_is			res;

	res.what = ft_strclone(what);
	res.data = ft_strclone(data);
	return (res);
}

int					get_values(struct s_alpha *current, char *categoryname, 
	char **lines)
{
	char			*name;
	struct s_alpha	*tmp;
	int				i;

	i = 0;
	name = getcatname(categoryname);
	while (lines[i] != '\0') //tant que pas de } correspondant; un { incremente un truc qui doit etre a 0 pour sortir;
	{
		if (buf[i][j] == '+')
		{
			rec(tmp, getcatname(&lines[i][j]), ft_is("s_alpha", get_values_(&lines[i][j], &lines[i + 1]))); //pas 
			i = getnext(&lines[i + 1]);
		}
		//correct mais bon la gestion devra se faire au dessus; pour chaque sous menu  au pire on fait i = getnext et puis zut;
		if (buf[i][j] == '-')
			rec(tmp, getcatname(&lines[i][j]), ft_is("val", get_value(&lines[i][j])));
		i++;
	}
	rec(current, name, tmp);
	rec(current, "namelist", &name);
	return (i);
}

struct s_alpha		*get_values_()
{
	
	{
		
	}
}
