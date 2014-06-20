/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 21:07:40 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/09 21:07:41 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "bircd.h"

double					square(double nbr)
{
	double				res;

	res = nbr * nbr;
	return (res);
}
//actions.c

int						prepare_move(int lrf, t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = MOVE;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].lrf = lrf;
	return (1);
}
//move(e, e->fds[cs].pl);

int						move_(t_env *e, int pl, int lrf)
{
	if (lrf == FW)
	{
		e->map.map[e->pl[pl].y][e->pl[pl].x].plonit--;
		if (e->pl[pl].dir == 1)
			e->pl[pl].y = (e->pl[pl].y + 1) % e->map.ylen;
		if (e->pl[pl].dir == 0 || e->pl[pl].dir == 4)
			e->pl[pl].x = (e->pl[pl].x + 1) % e->map.xlen;
		if (e->pl[pl].dir == 2)
			e->pl[pl].x = (e->pl[pl].x - 1) % e->map.xlen;
		if (e->pl[pl].dir == 3)
			e->pl[pl].y = (e->pl[pl].y - 1) % e->map.ylen;
		if (e->pl[pl].x < 0)
			e->pl[pl].x = e->map.xlen + e->pl[pl].x;
		if (e->pl[pl].y < 0)
			e->pl[pl].y = e->map.ylen + e->pl[pl].y;
		e->map.map[e->pl[pl].y][e->pl[pl].x].plonit++;
	}
	e->pl[pl].updated = 1;
	send_res(pl, "ok", e);
	return (1);
}

int						move(t_env *e, int pl)
{
	int					lrf;

	lrf = e->pl[pl].lrf;
	if (lrf == L)
		e->pl[pl].dir = (e->pl[pl].dir + 1) % 4;
	if (lrf == R)
		e->pl[pl].dir = (e->pl[pl].dir - 1) % 4;
	if (e->pl[pl].dir < 0)
		e->pl[pl].dir = 4 + e->pl[pl].dir;
	return (move_(e, pl, lrf));
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

int						change_pos(char *buf, t_env *e, int cs)
{
	int					x;
	int					y;
	int					dir;

	x = getnumb(buf, 0, 0);
	y = getnumb(buf, 1, 0);
	dir = getnumb(buf, 2, 0);
	e->map.map[e->pl[e->fds[cs].pl].y][e->pl[e->fds[cs].pl].x].plonit--;
	e->pl[e->fds[cs].pl].x = x;
	e->pl[e->fds[cs].pl].y = y;
	e->pl[e->fds[cs].pl].dir = dir;
	e->pl[e->fds[cs].pl].lvl = getnumb(buf, 3, 0);
	e->map.map[e->pl[e->fds[cs].pl].y][e->pl[e->fds[cs].pl].x].plonit++;
	return (1);
}

char					*getressource(int rsc)
{
	if (rsc == NOURRITURE)
		return ("nourriture");
	if (rsc ==  LINEMATE)
		return ("linemate");
	if (rsc == DERAUMERE)
		return ("deraumère");
	if (rsc == SIBUR)
		return ("sibur");
	if (rsc == MENDIANE)
		return ("mendiane");
	if (rsc == PHIRAS)
		return ("phiras");
	if (rsc == THYSTAME)
		return ("thystame");
	return (NULL);
}

char					*get_case_ressource(t_case tmpc, int i, int j,
	char *res)
{
	int					check;

	check = 0;
	while (j < NBRESSOURCE)
	{
		while (i < tmpc.r[j])
		{
			if (!check)
			{
				res = ft_strclone(getressource(j));
				check++;
			}
			else
			{
				res = ft_stradd(res, " ");
				res = ft_stradd(res, getressource(j));
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (!check)
		return (NULL);
	return (res);
}

char					*lookoncase_(int i, t_case tmpc, char *res)
{
	while (i < tmpc.plonit)
	{
		if (res == NULL)
			res = ft_strclone("joueur");
		else
			res = ft_stradd(res, " joueur");
		i++;
	}
	i = 0;
	while (i < tmpc.egg)
	{
		if (res == NULL)
			res = ft_strclone("egg");
		else
			res = ft_stradd(res, " egg");
		i++;
	}
	return (res);
}

char					*lookoncase(t_env *e, int yc, int xc, int number)
{
	t_case				tmpc;
	char				*res;
	int					y;
	int					x;

	x = xc % e->map.xlen;
	y = yc % e->map.ylen;
	if (x < 0)
		x += e->map.xlen;
	if (y < 0)
		y += e->map.ylen;
	res = NULL;
	(void)number;
	tmpc = e->map.map[yc % e->map.ylen][xc % e->map.xlen];
	x = 0;
	y = 0;
	res = get_case_ressource(tmpc, x, y, res);
	return (lookoncase_(x, tmpc, res));
}

int						getrc(int n, char xy, t_env *e)
{
	int					res;

	res = n;
	if (xy == 'X')
	{
		while (res < 0)
		{
			res += e->map.xlen;
		}
		res = res % e->map.xlen;
	}
	if (xy == 'Y')
	{
		while (res < 0)
		{
			res += e->map.ylen;
		}
		res = res % e->map.ylen;
	}
	return (res);
}

char					*check_cases_down(t_env *e, int y, int x, int hm)
{
	int					xc;
	int					count;
	char				*res;

	xc = hm;
	count = 1;
	y = getrc(y, 'Y', e);
	res = ft_strclone(lookoncase(e, y, getrc(x + hm, 'X', e), (hm * hm)));
	res = ft_stradd(res, ", ");
	while (--xc > 0)
	{
		res = ft_stradd(ft_stradd(res, lookoncase(e, y, getrc(x + xc, 'X', e),
			(hm * hm) + count)), ", ");
		count++;
	}
	xc = -1;
	while (++xc <= hm)
	{
		res = ft_stradd(res, lookoncase(e, y, getrc(x - xc, 'X', e), (hm * hm)
			+ count));
		if (xc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}

char					*check_cases_up(t_env *e, int y, int x, int hm)
{
	int					xc;
	int					count;
	char				*res;

	xc = hm;
	count = 1;
	y = getrc(y, 'Y', e);
	res = ft_strclone(lookoncase(e, y, getrc(x - hm, 'X', e), (hm * hm)));
	res = ft_stradd(res, ", ");
	while (--xc > 0) //pas bonne condition ici pour le moment
	{
		res = ft_stradd(ft_stradd(res, lookoncase(e, y, getrc(x - xc, 'X', e), (hm * hm)
			+ count)), ", ");
		count++;
	}
	xc = -1;
	while (++xc <= hm)
	{
		res = ft_stradd(res, lookoncase(e, y, getrc(x + xc, 'X', e), (hm * hm)
			+ count));
		if (xc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}

char					*check_cases_left(t_env *e, int y, int x, int hm)
{
	int					yc;
	int					count;
	char				*res;

	yc = hm;
	count = 1;
	x = getrc(x, 'X', e);
	res = ft_strclone(lookoncase(e, getrc(y - hm, 'Y', e), x, (hm * hm)));
	res = ft_stradd(res, ", ");
	while (--yc > 0)
	{
		res = ft_stradd(ft_stradd(res, lookoncase(e, getrc(y - yc, 'Y', e), x,
			(hm * hm) + count)), ", ");
		count++;
	}
	yc = -1;
	while (++yc <= hm)
	{
		res = ft_stradd(res, lookoncase(e, getrc(y + yc, 'Y', e), x, (hm * hm)
			+ count));
		if (yc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}

char					*check_cases_right(t_env *e, int y, int x, int hm)
{
	int					yc;
	int					count;
	char				*res;

	yc = hm;
	count = 1;
	x = getrc(x, 'X', e);
	res = ft_strclone(lookoncase(e, getrc(y + hm, 'Y', e), x, (hm * hm)));
	res = ft_stradd(res, ", ");
	while (--yc > 0)
	{
		res = ft_stradd(ft_stradd(res, lookoncase(e, getrc(y + yc, 'Y', e), x,
			(hm * hm) + count)), ", ");
		count++;
	}
	yc = -1;
	while (++yc <= hm)
	{
		res = ft_stradd(res, lookoncase(e, getrc(y - yc, 'Y', e), x, (hm * hm)
			+ count));
		if (yc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}

char					*seecaselvl(int lvl, int pl, t_env *e)
{
	e->pl[pl].x = getrc(e->pl[pl].x, 'X', e);
	e->pl[pl].y = getrc(e->pl[pl].y, 'Y', e);
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == UP)
		return (check_cases_up(e, ((e->pl[pl].y + lvl + 1)
			% e->map.ylen), e->pl[pl].x, lvl + 1));
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == DOWN)
		return (check_cases_down(e, ((e->pl[pl].y - lvl - 1)
			% e->map.ylen), e->pl[pl].x, (lvl + 1)));
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == LEFT)
		return (check_cases_left(e, e->pl[pl].y, ((e->pl[pl].x - 1 - lvl)
			% e->map.xlen), (lvl + 1)));
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == RIGHT)
		return (check_cases_right(e, e->pl[pl].y, ((e->pl[pl].x + 1 + lvl)
			% e->map.xlen), (lvl + 1)));
	return (NULL);
}
//.food
int						see(t_env *e, int pl)
{
	int					lv;
	char				*res;

	lv = e->pl[pl].lvl;
	res = NULL;
	res = ft_strclone("{");
	res = ft_stradd(res, lookoncase(e, e->pl[pl].y, e->pl[pl].x, 0));
	res = ft_stradd(res, ", ");
	while (lv > 0)
	{
		res = ft_stradd(res, seecaselvl((e->pl[pl].lvl - lv), pl, e));
		lv--;
	}
	res = ft_stradd(res, "}");
	send_res(pl, res, e);
	free(res);
	res = NULL;
	return (1);
}

int						prepare_see(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = SEE;
	e->pl[e->fds[cs].pl].cact++;
	return (1);
}

int						prepare_inv(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = INV;
	e->pl[e->fds[cs].pl].cact++;
	return (1);
}

int						aff_inv(t_env *e, int pl)
{
	int					i;
	int					j;
	char				*res;

	i = 0;
	j = 0;
	res = ft_strclone("{");
	while (j < NBRESSOURCE)
	{
		if (e->pl[pl].r[j] > 0)
		{
			if (i)
				res = ft_stradd(res, ", ");
			res = ft_stradd(res, getressource(j));
			res = ft_stradd(res, " ");
			res = ft_stradd(res, ft_itoa(e->pl[pl].r[j]));
			i = 1;
		}
		j++;
	}
	res = ft_stradd(res, "}");
	send_res(pl, res, e);
	free(res);
	res = NULL;
	return (1);
}

int						get_what(char *buf)
{
	if(!ft_strcmp(buf,"linemate"))
		return (LINEMATE);
	if(!ft_strcmp(buf,"deraumère"))
		return (DERAUMERE);
	if(!ft_strcmp(buf,"sibur"))
		return (SIBUR);
	if(!ft_strcmp(buf,"mendiane"))
		return (MENDIANE);
	if(!ft_strcmp(buf,"phiras"))
		return (PHIRAS);
	if(!ft_strcmp(buf,"thystame"))
		return (THYSTAME);
	if (!ft_strcmp(buf, "nourriture"))
		return (NOURRITURE);
	return (-1);
}

int						prepare_take(char *buf, t_env *e, int cs)
{
	if (ft_strlen(buf) > 2)
	{
		e->pl[e->fds[cs].pl].what = get_what(buf);
		ft_putstr(buf);
	}
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = TAKE;
	e->pl[e->fds[cs].pl].cact++;
	return (1);
}

int						take(t_env *e, int pl)
{
	if (e->map.map[e->pl[pl].y][e->pl[pl].x].r[e->pl[pl].what] > 0)
	{
		e->map.map[e->pl[pl].y][e->pl[pl].x].r[e->pl[pl].what]--;
		e->pl[pl].r[e->pl[pl].what]++;
		send_res(pl, "ok",  e);
	}
	else
		send_res(pl, "ko", e);
	return (1);
}

int						prepare_drop(char *buf, t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = DROP;
	e->pl[e->fds[cs].pl].cact++;
	if (ft_strlen(buf) > 2)
		e->pl[e->fds[cs].pl].what = get_what(buf);
	return (1);
}

int						drop(t_env *e, int pl)
{
	if (e->pl[pl].what > 0)
	{
		e->pl[pl].r[e->pl[pl].what]--;
		e->map.map[e->pl[pl].y][e->pl[pl].x].tmpr[e->pl[pl].what]++;
		e->map.map[e->pl[pl].y][e->pl[pl].x].r[e->pl[pl].what]++;
		send_res(pl, "ok", e);
		return (1);
	}
	send_res(pl, "ko", e);
	e->map.updated = 1;
	e->pl[pl].updated = 1;
	return (1);
}

int						eject(t_env *e, int pl)
{
	int					nbpl;
	char				*res;
	int					i;
	int					j;
	int					tmpx;
	int					tmpy;

	i = 0;
	j = 0;
	res = NULL;
	if (e->map.map[e->pl[pl].y][e->pl[pl].x].plonit > 1)
	{
		nbpl = e->map.map[e->pl[pl].y][e->pl[pl].x].plonit;
		while (i < nbpl && j < e->nbpl)
		{
			if (e->pl[j].y == e->pl[pl].y && e->pl[j].x == e->pl[pl].x
				&& j != pl)
			{
				tmpx = (cos(e->pl[pl].dir * (M_PI / 2))) * EJECTPOWA;
				tmpy = (sin(e->pl[pl].dir * (M_PI / 2))) * EJECTPOWA;
				e->pl[j].x = (int)(e->pl[j].x + tmpx)
				% e->map.xlen;
				e->pl[j].y = (int)(e->pl[j].y + tmpy)
				% e->map.ylen;
				res = ft_strclone("deplacement ");
				res = ft_stradd(res, ft_itoa(getdir((e->pl[pl].x - e->pl[j].x),
					(e->pl[pl].y - e->pl[j].y), e, j)));
				send_res(j, res, e);
				e->pl[j].updated = 1;
				free(res);
				res = NULL;
				e->map.map[e->pl[j].y][e->pl[j].x].plonit += 1;
				i++;
			}
			j++;
		}
		send_res(pl, "ok", e);
		res = ft_strclone("pex #");
		res = ft_stradd(res, ft_itoa(pl));
		send_res(-1, res, e);
		free(res);
		res = NULL;
		e->map.map[e->pl[pl].y][e->pl[pl].x].plonit -= i;
	}
	else
		send_res(pl, "ko", e);
	return (1);
	//"pex #n\n" - Un joueur expulse.

}

int						prepare_eject(t_env *e, int cs)
{
	int					pl;

	pl = e->fds[cs].pl;
	if (e->map.map[e->pl[pl].y][e->pl[pl].x].plonit > 1)
	{
		e->pl[e->fds[cs].pl].actionwait = 1;
		e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = EJECT;
		e->pl[e->fds[cs].pl].cact++;
	}
	return (1);
}
//eject(e, e->fds[cs].pl);

int						prepare_broadcast(char *buf, t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = BROADCAST;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].bc = ft_strclone(buf);
	return (1);
}
//broadcast(e, e->fds[cs].pl);

int						getdir(double x, double y, t_env *e, int pl)
{
	double				res;
	double				tmpx;
	double				tmpy;
	double				norm;
	double				angl;

	norm = sqrt(square(x) + square(y));
	res = 0;
	angl = 0;
	if (norm == 0)
		return (0);
	if (norm > 0)
	{
		tmpx = (double)x / (norm);
		tmpy = (double)y / (norm);
		if (tmpx != 0 && tmpy != 0)
		{
			if (tmpy < 0)
				angl = acos(tmpx) * (-1);
			if (tmpy >= 0)
				angl = acos(tmpx);
		}
		else if (tmpx == 0)
			angl = (M_PI / 2) * tmpy;
		else if (tmpy == 0 && tmpx == 1)
			angl = 0;
		else if (tmpy == 0 && tmpx == -1)
			angl = M_PI;
		angl -= (M_PI / 2) * e->pl[pl].dir;
		while (angl < 0)
			angl += (M_PI * 2);
		while (angl > (M_PI * 2))
			angl -= (M_PI * 2);
		tmpx = 0;
		while (res < 9)
		{

			if (angl >= (((M_PI / 4) * res) - (double)((M_PI * 2) / 16))
				&& angl <= ((M_PI / 4) * (res + 1)) - (double)((M_PI * 2) / 16))
			{
				if (res == 8)
					return (1);
				return (res + 1 );
			}
			res++;
		}
		if (res == 8)
			return (1);
	}
	return (res);
}

int						send_bc_to_pl(int pl, int dir, char *tosend, t_env *e)
{
	char				*res;

	res = ft_strclone("message ");
	res = ft_stradd(res, ft_itoa(dir));
	res = ft_stradd(res, ", ");
	res = ft_stradd(res, tosend);
	send_res(pl, res, e);
	free(res);
	res = NULL;
	return (1);
}

void					broadcast__(t_env *e, int i, int pl, int x)
{
	int					y;
	int					v1;
	int					v2;

	y = e->pl[pl].y;
	v1 = 0;
	v2 = 0;
	y = e->pl[pl].y;
	while ((y + v1) % e->map.ylen != e->pl[i].y)
		v1++;
	y = e->pl[i].y;
	while ((y + v2) % e->map.ylen != e->pl[pl].y)
		v2++;
	if (v1 > v2)
		y = v2;
	else
		y = -v1;
	send_bc_to_pl(i, getdir(x, y, e, i), e->pl[pl].bc, e);
}

void					broadcast_(t_env *e, int i, int pl)
{
	int					v2;
	int					v1;
	int					x;

	v2 = 0;
	v1 = 0;
	x = e->pl[pl].x;
	while ((x + v1) % e->map.xlen != e->pl[i].x)
		v1++;
	x = e->pl[i].x;
	while ((x + v2) % e->map.xlen != e->pl[pl].x)
		v2++;
	if (v1 > v2)
		x = +v2;
	else
		x = -v1;
	broadcast__(e, i, pl, x);
}

int						broadcast(t_env *e, int pl)
{
	char				*tmp;
	int					i;

	i = 0;
	while (i < e->nbpl)
	{
		if (i != pl)
			broadcast_(e, i, pl);
		i++;
	}
	send_res(pl, "ok", e);
	tmp = ft_strclone("pbc #");
	tmp = ft_stradd(tmp, ft_itoa(pl));
	tmp = ft_stradd(tmp, " ");
	tmp = ft_stradd(tmp, e->pl[pl].bc);
	send_res(-1, tmp, e);
	free(tmp);
	tmp = NULL;
	free(e->pl[pl].bc);
	e->pl[pl].bc = NULL;
	return (1);
}

int						check_ressources(int *ressources, int x, int y, t_env *e)
{
	int					i;
	int					c;

	i = 1;
	c = 0;
	while (i < NBRESSOURCE)
	{
		if (e->map.map[y][x].r[i] >= ressources[i])
			c++;
		i++;
	}
	i = 1;
	if (c == NBRESSOURCE - 1)
	{
		while (i < NBRESSOURCE)
		{
			e->map.map[y][x].r[i] -= ressources[i];
			i++;
		}
		return (1);
	}
	return (0);
}

void			incantation_pl(char **res, char **tograph, t_env *e,
	int pl)
{
	int					i;
	int					j;

	i = 0;
	j = -1;
	while (i < (e->pl[pl].lvl - 1) && ++j < e->nbpl)
	{
		if (e->pl[j].y == e->pl[pl].y && e->pl[j].x == e->pl[pl].x
			&& j != pl)
		{
			*tograph = ft_stradd(*tograph, " #");
			*tograph = ft_stradd(*tograph, ft_itoa(j));
			*res = ft_strclone("elevation en cours");
			*res = ft_stradd(*res, " niveau actuel : ");
			*res = ft_stradd(*res, ft_itoa(e->pl[j].lvl + 1));
			if (e->pl[j].cact < WACT)
			{
				e->pl[j].action[e->pl[j].cact] = LVLUP;
				e->pl[j].cact++;
			}
			send_res(j, *res, e);
			ft_memdel((void **)res);
			i++;
		}
	}
}

int						incantation_(int nbpl, int *ressources, t_env *e,
	int pl)
{
	char				*res;
	char				*tograph;

	if (e->map.map[e->pl[pl].y][e->pl[pl].x].plonit >= nbpl
		&& check_ressources(ressources, e->pl[pl].x, e->pl[pl].y, e))
	{
		tograph = ft_stradd(ft_strclone("pic "), ft_itoa(e->pl[pl].x));
		tograph = ft_stradd(tograph, " ");
		tograph = ft_stradd(tograph, ft_itoa(e->pl[pl].y));
		tograph = ft_stradd(tograph, " ");
		tograph = ft_stradd(tograph, ft_itoa(e->pl[pl].lvl));
		tograph = ft_stradd(tograph, " #");
		tograph = ft_stradd(tograph, ft_itoa(pl));
		incantation_pl(&res, &tograph, e, pl);
		send_res(-1, tograph, e);
		ft_memdel((void **)&tograph);
		res = ft_strclone("elevation en cours niveau actuel : ");
		res = ft_stradd(res, ft_itoa(e->pl[pl].lvl + 1));
		e->pl[pl].lvl++;
		send_res(pl, res, e);
		ft_memdel((void **)&res);
	}
	return (1);
}

int						lvl_up(t_env *e, int pl)
{
	e->pl[pl].lvl += 1;
	e->pl[pl].updated = 1;
	send_res(pl, e->pl[pl].bc, e);
	return (1);
}

int						incantation(t_env *e, int pl)
{
	int					lv;
	int					*res;

	lv = e->pl[pl].lvl;
	res = NULL;
	if (lv == 1)
		res = (int [7]){0, 1, 0, 0, 0, 0, 0};
	else if (lv == 2)
		res = (int [7]){0, 1, 1, 1, 0, 0, 0};
	else if (lv == 3)
		res = (int [7]){0, 2, 0, 1, 0, 2, 0};
	else if (lv == 4)
		res = (int [7]){0, 1, 1, 2, 0, 2, 0};
	else if (lv == 5)
		res = (int [7]){0, 1, 2, 1, 3, 0, 0};
	else if (lv == 6)
		res = (int [7]){0, 1, 2, 3, 0, 1, 0};
	else if (lv == 7)
		res = (int [7]){0, 2, 2, 2, 2, 2, 1};
	else
		return (0);
	incantation_(lv - 1, res, e, pl);
	return (1);
}

int						prepare_incantation(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = INCANTATION;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].actionwait = 1;
	return (1);
}

int						fork_player(t_env *e, int pl)
{
	time_t				tloc;
	char				*tog;

	tloc = 0;
	e->map.map[e->pl[pl].y][e->pl[pl].x].egg++;
	e->eggs = (t_egg *)realloc(e->eggs, (sizeof(t_egg)) * (e->nbegg + 1));
	tog = ft_strclone("enw #");
	tog = ft_stradd(tog, ft_itoa(e->nbegg));
	tog = ft_stradd(tog, " #");
	tog = ft_stradd(tog, ft_itoa(pl));
	tog = ft_stradd(tog, " ");
	tog = ft_stradd(tog, ft_itoa(e->pl[pl].x));
	tog = ft_stradd(tog, " ");
	tog = ft_stradd(tog, ft_itoa(e->pl[pl].y));
	send_res(-1, tog, e);
	free(tog);
	tog = NULL;
	e->eggs[e->nbegg].updated = 1;
	e->eggs[e->nbegg].pl = pl;
	e->eggs[e->nbegg].x = e->pl[pl].x;
	e->eggs[e->nbegg].y = e->pl[pl].y;
	e->eggs[e->nbegg].timer = time(&tloc);
	e->eggs[e->nbegg].used = 0;
	send_res(pl, "ok", e);
	e->nbegg++;
	return (1);
}

int						prepare_fork(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = FORK;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].actionwait = 1;
	return (1);
}

int						connect_nbr(t_env *e, int cs)
{
	int					pl;

	pl = e->fds[cs].pl;
	if (e->teams[e->fds[e->pl[pl].cs].team].nbpl < e->maxpl)
		send_res(pl, ft_itoa(e->maxpl - e->teams[e->fds[e->pl[pl].cs].team].nbpl), e);
	else
		send_res(pl, ft_itoa(e->teams[e->fds[e->pl[pl].cs].team].forknb), e);
	return (1);
}
//
