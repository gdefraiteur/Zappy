/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 14:14:15 by gdefrait          #+#    #+#             */
/*   Updated: 2014/04/27 14:14:16 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "/usr/X11R6/include/X11/X.h"
#include "fdf.h"
# include "libft.h"
# define COEF			(0.08)
# define WINDOW_X		2048
# define WINDOW_Y		1200
# define DIRCOEF		(0.4)
# define ANGLCOEF		3
# define ANGLVISION		90
# define RAYINC			0.04
# define H_COEF			350
# define SCREEN_DIST	1
# define VISION			10
# define MLX_KEY_LEFT	(65361)
# define MLX_KEY_RIGHT	(65363)
# define MLX_KEY_UP		(65362)
# define MLX_KEY_DOWN	(65364)

int						lenuntil(char *str, char c)
{
	int					i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char					*getuntil_(char *str, char c)
{
	char				*tmp;
	int					i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (lenuntil(str, c) + 1));
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (tmp);
		tmp[i] = str[i];
		tmp[i + 1] = '\0';
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (NULL);
}

void					draw_circle(t_coor center, double radius, t_map *map)
{
	double				angl;
	t_coor				vec;

	angl = 0;
	vec.x = 0;
	vec.y = 0;
	while (angl < (M_PI * 2))
	{
		vec.x = cos(angl);
		vec.y = sin(angl);
		draw_vector(center, vec, radius, map);
		angl += (M_PI / 99);
	}
	return ;
}

void					draw_dir(t_coor from, double dir, t_map *map,
	double len)
{
	t_coor				tmp;

	tmp.y = sin((dir * (M_PI / 2))) * (-1);
	tmp.x = cos((dir * (M_PI / 2)));
	draw_vector(from, tmp, len, map);
	return ;
}

unsigned long			get_color_(int rsc)
{
	if (rsc == 0)
		return (0xFF1213);
	if (rsc == 1)
		return (0xFFCC50);
	if (rsc == 2)
		return (0xFF12CC);
	if (rsc == 3)
		return (0x12FFCC);
	if (rsc == 4)
		return (0xFF50CC);
	if (rsc == 5)
		return (0x1250CC);
	if (rsc == 6)
		return (0xBB5013);
	return (0);
}

void					draw_block(t_coor from, double len, unsigned long color,
	t_map *map)
{
	t_coor				tmp;
	t_coor				tmp2;

	tmp.x = from.x;
	tmp.y = from.y;
	tmp2.x = 1;
	tmp2.y = 0;
	while (tmp.y - from.y < len)
	{
		map->tmpcolor = color;
		draw_vector(tmp, tmp2, len, map);
		tmp.y += 0.0004;
	}
	return ;
}

void					aff_inv(t_coor from, int *tab, int pl, t_map *map)
{
	int					i;
	t_coor				tmp;

	i = 0;
	while (i < 7)
	{
		if (pl == 2)
		{
			tmp.x = from.x - 0.5 + (i * 0.142);
			tmp.y = from.y - 0.5;
			draw_block(tmp, 0.142, get_color_(i), map);
			mlx_string_put(map->img.ptr, map->img.win,
				(int)((tmp.x + 0.1) * (WINDOW_X / map->map[0].len)),
				(int)((tmp.y + 0.142) * (WINDOW_Y / map->len)), 0x000000,
			ft_itoa(tab[i]));
		}
		if (pl == 3)
		{
			tmp.x = from.x - 0.5;
			tmp.y = from.y - 0.5 + (i * 0.122) + 0.142;
			draw_block(tmp, 0.122, get_color_(i), map);
			tmp.y += 0.122;
			tmp.x += 0.05;
			mlx_string_put(map->img.ptr, map->img.win,
				(int)(tmp.x * (WINDOW_X / map->map[0].len)),
				(int)(tmp.y * (WINDOW_Y / map->len)), 0x000000,
			ft_itoa(tab[i]));
		}
		i++;
	}
}

void					addcursor(t_map *map)
{
	t_coor		c1;
	t_coor		c2;
	t_coor		c3;
	t_coor		tmp;
	t_coor		norm;
	double		x;
	int			*tab;
	double		y;

	c1 = map->map[(int)map->cursor.pos.y].truexy[(int)map->cursor.pos.x + 1];
	c2 = map->map[(int)map->cursor.pos.y + 1].truexy[(int)map->cursor.pos.x];
	c3.x = c1.x;
	c3.y = c1.y;
	x = 0;
	y = 0;
	tmp = map->map[(int)map->cursor.pos.y].truexy[(int)map->cursor.pos.x];
	tmp.x += 0.5;
	tmp.y += 0.5;
	(*map).tmpcolor = 0xDD50EE;
	draw_circle(tmp, 0.2, map);
	map->tmpcolor = 0xFFFFFF;
	draw_dir(tmp, map->tmpdir, map, 0.2);
	tab = (int [7]){0, 1, 0, 0, 0, 0, 0};
	aff_inv(tmp, tab, 2, map);
	aff_inv(tmp, tab, 3, map);
	mlx_string_put(map->img.ptr, map->img.win,
				(int)(c1.x * (WINDOW_X / map->map[0].len)),
				(int)(c1.y * (WINDOW_Y / map->len)), 0xFF0000,
			"yoyo");
}

void					move_cursor(t_map *map, int y, int x)
{
	if (map->cursor.pos.y + (int)y < (map->len - 1)
		&& map->cursor.pos.x + (int)x <
		map->map[(int)map->cursor.pos.y + (int)y].len && map->cursor.pos.y
		+ (int)y >= 0 && map->cursor.pos.x + (int)x >= 0)
	{
		map->cursor.pos.y += y;
		map->cursor.pos.x += x;
	}
	addcursor(map);
	return ;
}

void					draw_line_(t_coor c1, t_coor c2, t_map *map, int col)
{
	t_coor				norm;
	double				x;
	double				y;
	unsigned int		color;

	x = 0;
	y = 0;
	color = 0;
	if (c1.x != c2.x || c1.y != c2.y)
	{
		norm = normalize(c1, c2);
		while (sqrt(square(x) + square(y)) < norm.len)
		{
			if ((int)(c1.x + x) < WINDOW_X && (int)(c1.x + x) > 0
				&& (int)(c1.y + y) < WINDOW_Y && (int)(c1.y + y) > 0)
			{
				color = 0;
				map->img = pixel_put(map->img, (int)(c1.x + x),
				(int)(c1.y + y), color);
			}
			x += norm.x / 2;
			y += norm.y / 2;
		}
	}
	return ;
}

void					addwall(double sx, double dist, t_map *map, int color)
{
	t_coor				from;
	t_coor				to;
	double				h;

	to.x = ((WINDOW_X / 60) * sx);
	from.x = ((WINDOW_X / 60) * sx);
	h = WINDOW_Y - 2;
	from.y = ((WINDOW_Y / 2) - (h / 2));
	to.y = ((WINDOW_Y / 2) + (h / 2));
	draw_line_(from, to, map, color);
	return ;
}

void					clean_screen(t_map *map)
{
	double				sx;

	sx = 0;
	while (sx < 60)
	{
		addwall(sx, (-1), map, 0);
		sx += (double)(60 / (double)WINDOW_X);
	}
	return ;
}

int						eventkeypress(int keycode, void *p_data)
{
	t_map				*map;

	map = (t_map *)p_data;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

int						expose(t_map *d)
{
	put_image(d->img);
	return (0);
}

t_cursor				init_cursor(void)
{
	t_cursor			cursor;

	cursor.pos.x = 4;
	cursor.pos.y = 5;
	cursor.menumode = 0;
	cursor.currentitem = NULL;
	return		(cursor);
}

void					aff_egg(int i, t_env *e)
{
	t_coor				from;

	if (e->gegg[i].alive)
	{
		from.x = e->gegg[i].pos.x + 0.8;
		from.y = e->gegg[i].pos.y + 0.8;
		e->mapp.tmpcolor = 0x13CC50;
		draw_circle(from, 0.05, &e->mapp);
	}
	return ;
}

void					aff_pl(int i, t_env *e)
{
	t_coor				from;
	time_t				tloc;

	if (if (e->gpls[i].bct && 
		time(&tloc) - e->gpls[i].bct < 2)
	{
		mlx_string_put(map->img.ptr, map->img.win,
				(int)(c1.x * (WINDOW_X / map->map[0].len)),
				(int)(c1.y * (WINDOW_Y / map->len)), 0xFF0000,
			e->gpls[i].bc);
		free(e->gpls[i].bc);
		e->gpls[i].bc = NULL;
		e->gpls[i].bct = 0;
	}
	from.x = e->gpls[i].pos.x + 0.5;
	from.y = e->gpls[i].pos.y + 0.5;
	e->tmpcolor = 0xFF5013;
	draw_circle(from, 0.08, &e->mapp);
	e->tmpcolor = 0x13FF50;
	draw_dir(from, e->gpls[i].dir, &e->mapp, 0.08);
	aff_inv(e->gpls[i].pos, e->gpls[i].inv, 0, &e->mapp);
	return ;
}

void					update_all(t_env *e)
{
	int					i;

	i = 0;
	while (i < e->nbgeggs)
	{
		aff_egg(i, e);
		i++;
	}
	i = 0;
	while (i < e->nbgpl)
	{
		aff_pl(i, e);
		i++;
	}
}

int						update_map(t_env *e)
{
	clean_screen(&e->mapp);
	e->mapp.tmpdir = 0;
	e->mapp = affmap(e->mapp);
	e->mapp = update_all(e);
	put_image(e->mapp.img);
	mlx_hook(e->mapp.img.win, KeyPress, KeyPressMask, eventkeypress, &map);
	mlx_expose_hook(e->mapp.img.win, expose, &map);
	mlx_loop(e->mapp.img.ptr);
	return (0);
}

int						getnumb(char *str, int n, char c)
{
	char				**split;
	int					res;

	split = ft_strsplit(str, ' ');
	res = 0;
	if (c != 0)
		(void)c;
	if (n <= (int)ft_sstrlen(split))
		res = ft_atoi(split[n]);
	sstrmemdel(&split);
	return (res);
}

void					empty_map_line(t_env *e, int line)
{
	int					i;

	i = 0;
	while (i < e->mapp.xlen)
	{
		e->mapp.map[line].truexy[i].x = i;
		e->mapp.map[line].truexy[i].y = line;
		e->mapp.map[line].tab[i] = 0;
		j = -1;
		while (++j < 7)
			e->mapp.map[line].truexy[i].res[j] = 0;
		i++;
	}
	return ;
}

void					g_map_create(t_env *e)
{
	e->mapp.map = (t_ntab *)malloc(sizeof(t_ntab) * e->mapp.ylen);
	while (i < e->mapp.ylen)
	{
		e->mapp.map[i].tab = (int *)malloc(sizeof(int) * e->mapp.xlen);
		e->mapp.map[i].truexy = (t_coor *)malloc(sizeof(t_coor) * e->mapp.xlen);
		empty_map_line(e, i);
		i++;
	}
}

void					set_msz(char *buf, t_env *e)
{
	e->mapp.xlen = getnumb(buf, 0, ' ');
	e->mapp.ylen = getnumb(buf, 1, ' ');
	g_map_create(e);
	e->mszset = 1;
}

void					set_tu(char *buf, t_env *e)
{
	e->tu = getnumb(buf, 0);
	e->tuset = 1;
}

void					set_tna(char *buf, t_env *e)
{
	if (e->gteams == NULL)
		e->gteams = (char **)malloc(sizeof(char *) * 1);
	else
		e->gteams = (char **realloc(sizeof(char *) * (e->nbteam + 1)));
	e->gteams[e->nbteam] = ft_strclone(buf);
	e->nbteam++;
}

void					modif_case(t_env *e, char *buf)
{
	int					x;
	int					y;
	int					i;

	i = -1;
	x = getnumb(buf, 0, ' ');
	y = getnumb(buf, 1, ' ');
	while (++i < 7)
		e->mapp.map[y].truexy[x].res[i] = getnumb(buf, i + 2, ' ');
	return ;
}

void					new_gpl(char *buf, t_env *e)
{
	e->gpls[e->nbgpl].pos.x = getnumb(buf, 1, ' ');
	e->gpls[e->nbgpl].pos.y = getnumb(buf, 2, ' ');
	e->gpls[e->nbgpl].dir = getnumb(buf, 3, ' ');
	e->gpls[e->nbgpl].lvl = getnumb(buf, 4, ' ');
	e->gpls[e->nbgpl].alive = 1;
	return ;
}

void					new_gegg(char *buf, t_env *e)
{
	e->geggs[e->nbgegg].pos.x = getnumb(buf, 2, ' ');
	e->geggs[e->nbgegg].pos.y = getnumb(buf, 3, ' ');
	e->geggs[e->nbgegg].alive = 1;
	return ;
}

void					g_new_pl(t_env *e, char *buf)
{
	if (e->gpls == NULL)
		e->gpls = (t_gpl *)malloc(sizeof(t_gpl) * 1);
	else
		e->gpls = (t_gpl *)realloc(e->gpls, (sizeof(t_gpls) * (e->nbgpl + 1)));
	new_gpl(buf, e);
	e->nbgpl++;
	return ;
}
void					g_new_egg(t_env *e, char *buf)
{
	if (e->geggs == NULL)
		e->geggs = (t_gegg *)malloc(sizeof(t_gegg) * 1);
	else
		e->geggs = (t_gegg *)realloc(e->geggs,
			(sizeof(t_gegg) * (e->nbgegg + 1)));
	new_gegg(buf, e);
	e->nbgegg++;
}

void					eclosion(t_env *e, char *buf)
{
	int					egnb;

	egnb = getnumb(&buf[1], 0, ' ');
	e->geggs[egnb].alive = 0;
	return ;
}

void					g_player_move(t_env *e, char *buf)
{
	int					plnb;

	plnb = getnumb(&buf[1], 0, ' ');
	update_pl(e, plnb, buf);
	e->gpl[plnb].pos.x = getnumb(buf, 1, ' ');
	e->gpl[plnb].pos.y = getnumb(buf, 2, ' ');
	e->gpl[plnb].dir = getnumb(buf, 3, ' ');
	return ;
}

void					g_incantation(t_env *e, char *buf)
{
	int					x;
	int					y;
	time_t				tloc;

	x = getnumb(buf, 0, ' ');
	y = getnumb(buf, 1, ' ');
	e->mapp.map[y].truexy[x].event = INCANTATION;
	e->mapp.map[y].truexy[x].evtimer = time(&tloc);
	return ;
}

void					g_fork(t_env *e, char *buf)
{
	int					plnb;
	int					x;
	int					y;

	plnb = getnumb(&buf[1], 0, ' ');
	x = e->gpl[plnb].pos.x;
	y = e->gpl[plnb].pos.y;
	e->mapp.map[y].truexy[x].event = FORK;
	e->mapp.map[y].truexy[x].evtimer = time(&tloc);
	return ;
}

void					game_end(t_env *e, char *buf)
{
	ft_putstr("GAME OVER:\nwinning team:");
	ft_putstr(buf);
	return ;
}

void					g_pin(t_env *e, char *buf)
{
	int					plnb;
	int					i;

	i = -1;
	plnb = getnumb(&buf[1], 0, ' ');
	while (++i < 7)
		e->gpls[plnb].inv[i] = getnumb(buf, i + 1, ' ');
	return ;
}

void					g_broadcast(t_env *e, char *buf)
{
	int					plnb;
	time_t				tloc;

	plnb = getnumb(&buf[1], 0, ' ');
	if (plnb < e->nbgpl)
	{
		e->gpls[plnb].bct = time(&tloc);
		if (buf[lenuntil(buf, ' ') + 1] != '\0')
			e->gpls[plnb].bc = ft_strclone(&buf[lenuntil(buf, ' ') + 1]);
	}
	return ;
}

int						foundop_(char *tmp, char *buf, t_env *e, int cs)
{
	if (!ft_strcmp (tmp, "msz "))
		set_msz(&buf[4], e);
	else if (!ft_strcmp(tmp, "sgt "))
		set_tu(&buf[4], e);
	else if (!ft_strcmp(tmp, "tna "))
		set_tna(&buf[4], e);
	else if (e->mszset && e->tuset)
	{
		if (!ft_strcmp(tmp, "bct "))
			modif_case(e, &buf[4]);
		else if (!ft_strcmp(tmp, "pnw "))
			g_new_pl(e, &buf[4]);
		else if (!ft_strcmp(tmp, "enw "))
			g_new_egg(e, &buf[4]);
		else if (!ft_strcmp(tmp, "ebo "))
			eclosion(e, &buf[4]);
		else if (!ft_strcmp(tmp, "ppo "))
			g_player_move(e, &buf[4]);
		else if (!ft_strcmp(tmp, "pic "))
			g_incantation(e, &buf[4]);
		else if (!ft_strcmp(tmp, "pfk "))
			g_fork(e, &buf[4]);
		else if (!ft_strcmp(tmp, "seg "))
			game_end(e, &buf[4]);
		else if (!ft_strcmp(tmp, "pbc "))
			g_broadcast(e, &buf[4]);
		else if (!ft_strcmp(tmp, "pin "))
			g_pin(e, &buf[4]);
		return (- 1);
	}
	return (-1);
}

int						get_opt__(char *buf, t_env *e, int cs)
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
		if (foundop_(tmp, tmp2, e, cs) != -1)
			break ;
		i++;
	}
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&tmp2);
	if (strchr(buf, '\n') != NULL && buf[lenuntil(buf, '\n') + 1] != '\0')
		return (get_opt_(&buf[lenuntil(buf, '\n') + 1], e, cs));
	return (1);
}

void						getmap_(int socket_desc, t_env *e)
{
	char					*buf;
	int						i;

	i = 0;
	write(socket_desc, "GRAPHIC\n", ft_strlen("GRAPHIC\n"));
	while (1)
	{
		i = read(socket_desc, &buf, 4096);
		buf[i - 1] = '\n';
		get_opt__(buf, e, socket_desc);
		free(buf);
		buf = NULL;
		update_map(e);
	}
	return ;
}

int							main(int argc, char **argv)
{
	t_servaddress			address;
	int						socket_desc;
	t_env					e;
	t_connect				server;

	(void)address;
	(void)server;
	server.proto = getprotobyname("tcp");
	server.read_size = 0;
	if (argc != 3)
		return (0);
	address.ip = ft_strclone(argv[1]);
	address.port = ft_atoi(argv[2]);
	socket_desc = socket(PF_INET, SOCK_STREAM, server.proto->p_proto);
	server.serv.sin_family = AF_INET;
	server.serv.sin_addr.s_addr = inet_addr(address.ip);
	server.serv.sin_port = htons(address.port);
	e.mszset = 0;
	e.tuset = 13;
	e.mapp.img = create_img(e.mapp.img);
	if (connect(socket_desc, (struct sockaddr *)&server.serv,
		sizeof(server.serv)) < 0)
	{
		ft_putstr("Connection error, maybe your stupid");
		ft_putstr("and entered wrong server address.");
		return (1);
	}
	getmap_(socket_desc, &e);
	return (1);
}
