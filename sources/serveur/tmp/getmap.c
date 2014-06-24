/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:15:22 by gdefrait          #+#    #+#             */
/*   Updated: 2014/04/27 14:15:23 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>

t_map			getmap(char *file)
{
	t_map		res;
	int			i;
	int			fd;

	((fd = open(file, (O_RDONLY))) == -1) ? exit(EXIT_FAILURE) : (void)i;
	i = 0;
	res.lines = (char **)malloc(sizeof(char *) * 5);
	while (get_next_line(fd, &res.lines[0]))
		i++;
	sstrmemdel((void ***)res.lines);
	close(fd);
	((fd = open(file, (O_RDONLY))) == -1) ? exit(EXIT_FAILURE) : (void)i;
	res.lines = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (get_next_line(fd, &res.lines[i]))
	{
		res.lines = (char **)realloc(res.lines, (sizeof(char *) * (i + 5)));
		i++;
	}
	res.len = i;
	res = getpoints(res);
	close(fd);
	return (res);
}

t_map			getpoints(t_map map)
{
	int			i;

	i = 0;
	map.map = (t_ntab *)malloc(sizeof(t_ntab) * map.len + 5);
	while (i < map.len)
	{
		map.map[i] = get_tab(map.lines[i], i);
		i++;
	}
	map.len = i;
	return (map);
}

int				ft_sstrlen(char **sstr)
{
	int			i;

	i = 0;
	while (sstr[i] != '\0')
		i++;
	return (i);
}

t_ntab			get_tab(char *line, int y)
{
	int			i;
	char		**numbs;
	t_ntab		res;

	i = 0;
	if (line != NULL)
	{
		numbs = ft_strsplit(line, ' ');
		res.tab = (int *)malloc(sizeof(int) * (ft_sstrlen(numbs) + 5));
		res.truexy = (t_coor *)malloc(sizeof(t_coor) * (ft_sstrlen(numbs) + 5));
		while (numbs[i] != '\0')
		{
			res.tab[i] = ft_atoi(numbs[i]);
			res.truexy[i] = gettruexy(i, y, res.tab[i], ft_sstrlen(numbs));
			i++;
		}
		res.len = i;
	}
	ft_memdel((void **)&line);
	return (res);
}

t_coor			gettruexy(int x, int y, int h, int len)
{
	t_coor		res;

	res.x = (double)x + COEF * h;
	res.y = (double)y + COEF * h;
	res.h = h;
	return (res);
}
