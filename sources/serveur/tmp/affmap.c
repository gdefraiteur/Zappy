/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:14:57 by gdefrait          #+#    #+#             */
/*   Updated: 2014/04/27 14:14:58 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

double				square(double nbr)
{
	double			res;

	res = nbr * nbr;
	return (res);
}

t_map				affmap(t_map map)
{
	int				y;

	y = 0;
	while (y < map.len)
	{
		map = draw_lines(y, map);
		y++;
	}
	return (map);
}

int					gettimer(int event)
{
	if (event == INCANTATION)
		return (300);
	if (event == FORK)
		return (42);
}

void				check_event(t_map *map, int y, int x)
{
	int				event;

	event = map->map[y].truexy[x].event;
	if ((time(&tloc) - map->map[y].truexy[x].evtimer)
		< (gettimer(map->map[y].truexy[x].event) / e->tuset) && event)
	{
		if (event == INCANTATION)
		{
			mlx_string_put(map->img.ptr, map->img.win,
				(int)((x + 0.5) * (WINDOW_X / map->map[0].len)),
				(int)((y + 0.8) * (WINDOW_Y / map->len)), 0xFF0000,
			"incantation");
		}
		if (event == FORK)
		{
			mlx_string_put(map->img.ptr, map->img.win,
				(int)((x + 0.5) * (WINDOW_X / map->map[0].len)),
				(int)((y + 0.8) * (WINDOW_Y / map->len)), 0xFF0000,
			"fork");
		}
		map->map[y].truexy[x].event = 0;
		map->map[y].truexy[x].evtimer = 0;
	}
	return ;
}

t_map				draw_lines(int y, t_map map)
{
	int				x;

	x = 0;
	while (x < map.map[y].len)
	{
		if (y + 1 < map.len)
		{
			if (x < map.map[y + 1].len)
			{
				map = draw_line(map.map[y].truexy[x],
				map.map[y + 1].truexy[x], map, y);
			}
		}
		if (x + 1 < map.map[y].len)
			map = draw_line(map.map[y].truexy[x],
			map.map[y].truexy[x + 1], map, y);
		if (map.map[y].truexy[x].event)
				check_event(&map, y, x);
		x++;
	}
	return (map);
}

void					draw_vector(t_coor from, t_coor vector, double len, 
	t_map *map)
{
	t_coor				norm;
	t_coor				tmp;
	t_coor				tmp2;

	tmp.x = vector.x + from.x;
	tmp.y = vector.y + from.y;
	tmp2 = from;
	norm = normalize(from, tmp);
	while (sqrt(square(tmp2.x - from.x) + square(tmp2.y - from.y)) < len)
	{
		(*map).img = pixel_put((*map).img,
			(int)((tmp2.x) * (WINDOW_X / (*map).map[0].len)),
			(int)((tmp2.y) * (WINDOW_Y / (*map).len)), (*map).tmpcolor);
		tmp2.x += norm.x / 150;
		tmp2.y += norm.y / 150;
	}
	return ;
}

t_map				draw_line(t_coor c1, t_coor c2, t_map map, int j)
{
	t_coor			norm;
	double			x;
	double			y;
	unsigned int	color;

	x = 0;
	y = 0;
	color = 0xCC55EE;
	if (c1.h >= 10 || c2.h >= 10)
		color = 0x12CCCC;
	if (c1.h >= 12 || c2.h >= 12)
		color = 0x8520FF;
	if (c1.x != c2.x || c1.y != c2.y)
	{
		norm = normalize(c1, c2);
		while (sqrt(square(x) + square(y)) < norm.len)
		{
			map.img = pixel_put(map.img, (int)((c1.x + x)
				* (WINDOW_X / map.map[j].len)), (int)((c1.y + y)
				* (WINDOW_Y / map.len)), color);
			x += norm.x / 20;
			y += norm.y / 20;
		}
	}
	return (map);
}

t_coor				normalize(t_coor c1, t_coor c2)
{
	t_coor			res;
	double			norm;

	res.x = c2.x - c1.x;
	res.y = c2.y - c1.y;
	norm = sqrt(square(res.x) + square(res.y));
	res.x = res.x / norm;
	res.y = res.y / norm;
	res.len = norm;
	return (res);
}
