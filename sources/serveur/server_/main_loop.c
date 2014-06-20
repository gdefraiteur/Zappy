/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:17:10 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:17:11 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

/*

//fonctions:
"pex #n\n" - Un joueur expulse.
"pbc #n M\n" Un joueur fait un broadcast.
"pic X Y L #n #n …\n" - Premier joueur lance l’incantation pour tous les 
suivants sur la case. 
"pfk #n\n" - Le joueur pond un œuf. 
"enw #e #n X Y\n" - L’œuf a été pondu sur la case par le joueur. 
"pdr #n i\n" - Le joueur jette une ressource. 
"pgt #n i\n" - Le joueur prend une ressource. 

//automation:
"bct X Y q q q q q q q\n" "bct X Y\n" Contenu d’une case de la carte. 
//"bct X Y q q q q q q q\n" * nbr_cases "mct\n" Contenu de la carte (toutes les cases). 
"ppo #n X Y O\n" "ppo #n\n" Position d’un joueur. 
"plv #n L\n" "plv #n\n" Niveau d’un joueur. 
"pin #n X Y q q q q q q q\n" "pin #n\n" Inventaire d’un joueur. 
"pdi #n\n" - Le joueur est mort de faim. 
"eht #e\n" - L’œuf éclot.
"ebo #e\n" - Un joueur s’est connecté pour l’œuf. 
"edi #e\n" - L’œuf éclos est mort de faim. 
"seg N\n" - Fin du jeu. L’équipe donnée remporte la partie. 
"smg M\n" - Message du serveur. 
"sbp\n" - Mauvais paramètres pour la commande. 

//echange
"sgt T\n" "sgt\n" Demande de l’unité de temps courante sur le 
serveur. 
"sgt T\n" "sst T\n" Modification de l’unité de temps sur le serveur. 

//initialisation:
"msz X Y\n" "msz\n" Taille de la carte. 
"tna N\n" * nbr_equipes "tna\n" Nom des équipes. 
"bct X Y q q q q q q q\n" "bct X Y\n" Contenu d’une case de la carte. 


//connect "pnw #n X Y O L N\n" - Connexion d’un nouveau joueur. 
*/
//g_send.c
void		g_send_pl(t_pl pl, int i, t_env *e)
{
	char	*tmp;

	tmp = NULL;
	if (e->graphnb)
	{
		tmp = ft_strclone("ppo #");
		tmp = ft_stradd(tmp, ft_itoa(i));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(pl.x));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(pl.y));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(pl.dir));
		tmp = ft_stradd(tmp, "\n");
		send_res(-1, tmp, e);
		free(tmp);
		tmp = NULL;
	}
	return ;
}

void		g_send_case(t_case c, int x, int y, t_env *e)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if (e->graphnb)
	{
		tmp = ft_strclone("bct ");
		tmp = ft_stradd(tmp, ft_itoa(x));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(y));
		i = -1;
		while (++i < NBRESSOURCE)
		{
			tmp = ft_stradd(tmp, " ");
			tmp = ft_stradd(tmp, ft_itoa(c.r[i]));
		}
		send_res(-1, tmp, e);
		free(tmp);
		tmp = NULL;
	}
	return ;
}

void	g_send_map(t_env *e)
{
	int	j;
	int	i;

	i = -1;
	j = -1;
	while (++i < e->map.ylen)
	{
		while (++j < e->map.xlen)
			g_send_case(e->map.map[i][j], j, i, e);
		j = -1;
	}
	return ;
}

void	g_send_egg(t_egg egg, int pl, int eggnb, t_env *e)
{
	char	*res;

	if (!egg.used)
	{
		res = ft_strclone("enw #");
		res = ft_stradd(res, ft_itoa(eggnb));
		res = ft_stradd(res, " #");
		res = ft_stradd(res, ft_itoa(pl));
		res = ft_stradd(res, " ");
		res = ft_stradd(res, ft_itoa(egg.x));
		res = ft_stradd(res, " ");
		res = ft_stradd(res, ft_itoa(egg.y));
		send_res(-1, res, e);
		res = NULL;
		free(res);
	}
	return ;
}
//
//check_pl.c
void	load_function(int action, int pl, t_env *e)
{
	if (action == MOVE)
		move(e, pl);
	if (action == TAKE)
		take(e, pl);
	if (action == DROP)
		drop(e, pl);
	if (action == EJECT)
		eject(e, pl);
	if (action == FORK)
		fork_player(e, pl);
	if (action == INCANTATION)
		incantation(e, pl);
	if (action == CNB)
		connect_nbr(e, pl);
	if (action == BROADCAST)
		broadcast(e, pl);
	if (action == LVLUP)
		lvl_up(e, pl);
	if (action == INV)
		aff_inv(e, pl);
	if (action == SEE)
		see(e, pl);
}

int			getacttime(int action)
{
	int		res;

	if (action == MOVE)
		res = 7;
	if (action == TAKE)
		res = 7;
	if (action == DROP)
		res = 7;
	if (action == EJECT)
		res = 7;
	if (action == FORK)
		res = 42;
	if (action == INCANTATION)
		res = 300;
	if (action == CNB)
		res = 0;
	if (action == BROADCAST)
		res = 7;
	if (action == LVLUP)
		res = 300;
	if (action == INV)
		res = 1;
	if (action == SEE)
		res = 7; //.nour
	return (res);
}
//
//serv_update.c
//bizarre cette fin de fonction: voir si elle a toujours des consequences.
//
void		init_graph_(t_env *e, int i)
{
	i = e->wpl;
	while (i > 0)
	{
		if (e->forknb > 0)
		{
			e->fds[e->waitingpl[i]].pl = e->fork[e->forknb];
			e->pl[e->fork[e->forknb]].cs = e->waitingpl[i];
			e->wpl--;
			e->forknb--;
		}
		i--;
	}
	return ;
}

void		init_graph(t_env *e, int cs)
{
	int		i;

	i = 0;
	(void)cs;
	while (i < e->nbpl)
	{
		if (e->pl[i].cs >= 0)
			g_send_pl(e->pl[i], i, e);
		e->pl[i].updated = 0;
		i++;
	}
	g_send_map(e);
	i = e->nbegg;
	while (i > 0)
	{
		if (!e->eggs[i].used)
		{
			g_send_egg(e->eggs[i], e->eggs[i].pl, i, e);
			e->eggs[i].updated = 0;
		}
		i--;
	}
	init_graph_(e, i);
	return ;
}

void		init_food(t_pl *pl)
{
	int		i;

	i = 1;
	pl->r[0] = START_FOOD;
	while (i < 7)
	{
		pl->r[i] = 0;
		i++;
	}
	return ;
}

void		new_tpl(t_env *e, int cs, int newpl, t_pl *res)
{
	if (newpl)
	{
		res->x = rand() % e->map.xlen;
		res->y = rand() % e->map.ylen;
		init_food(res);
		res->dir = (rand() % 4) * (M_PI / 2);
		e->map.map[res->y][res->x].plonit++;
	}
	res->action[0] = 0;
	res->cact = 0;
	res->actionwait = 0;
	res->bc = NULL;
	res->updated = 1;
	res->cs = cs;
	res->lvl = 1;
	res->timer = 0;
	res->what = 0;
	res->team = 0;
	res->alive = 1;
	return ;
}

t_pl		new_pl(t_env *e, t_egg egg, int id)
{
	t_pl	res;

	res.x = egg.x;
	res.y = egg.y;
	e->map.map[egg.y][egg.y].plonit++;
	res.action[0] = 0;
	res.cact = 0;
	res.actionwait = 0;
	res.bc = NULL;
	res.updated = 1;
	init_food(&res);
	res.dir = (rand() % 4) * (M_PI / 2);
	res.cs = -1;
	res.lvl = 1;
	res.timer = 0;
	res.cact = 0;
	res.alive = 1;
	res.what = 0;
	res.team = e->fds[e->pl[egg.pl].cs].team;
	e->teams[res.team].fork = (int *)realloc(e->teams[res.team].fork,
		(sizeof(int) * (e->teams[res.team].forknb + 1)));
	e->teams[res.team].fork[e->teams[res.team].forknb] = id;
	e->teams[res.team].forknb++;
	return (res);
}

void	rand_generate(t_env *e)
{
	static int	seed = 0;
	int			i;
	int			seednb;
	int			seedx;
	int			seedy;
	int			seedr;

	srand(seed);
	i = 0;
	seed += 3;
	seednb = rand() % 9; //faire apres que ce soit plutot en rapport avec la taille terrain
	while (i < seednb)
	{
		seedx = rand() % e->map.xlen;
		seedy = rand() % e->map.ylen;
		seedr = rand() % NBRESSOURCE;
		e->map.map[seedy][seedx].r[seedr] += i % 2;
		i++;
	}
	return ;
}
//Faire page de stat globaux pour savoir ou en est chaque pl
//genre pl:
//dir:
//posx:
//posy:
//on peut ptet faire une mini interface graphique interne au serveur
//mouais enfin qui mettrait juste le num de la dir a l endroit du joueur et
//des 0 ailleur avec des tabulations.

void		check_pl_(t_env *e, int i, int tmp, time_t tloc)
{
	if (e->pl[i].cact > 0)
	{
		if (time(&tloc) - e->pl[i].timer
			> (getacttime(e->pl[i].action[0]) / e->time_unit))
			{
				load_function(e->pl[i].action[0], i, e);
				while (tmp < e->pl[i].cact)
				{
					e->pl[i].action[tmp] = e->pl[i].action[tmp + 1];
					tmp++;
				}
				e->pl[i].cact--;
				if (e->pl[i].cact > 0)
					e->pl[i].timer = time(&tloc);
			}
	}
	if (e->pl[i].updated)
	{
		g_send_pl(e->pl[i], i, e);
		e->pl[i].updated = 0;
	}
	return ;
}

void		check_pl(int *check, t_env *e, int i, int tmp)
{
	time_t	tloc;

	if (time(&tloc) - e->general_timer > 126 / e->time_unit)
	{
		if (e->pl[i].r[0] > 0)
		{
			e->pl[i].r[0]--;
			*check = 1;
		}
		else
			e->pl[i].alive = 0;
	}
	check_pl_(e, i, tmp, tloc);
	return ;
}

void		check_wpl(t_env *e, int i, int tmp)
{
	if (e->teams[e->fds[e->waitingpl[i]].team].nbpl < e->maxpl)
	{
		e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
		e->fds[e->waitingpl[i]].pl = e->nbpl;
		new_tpl(e, e->waitingpl[i], 1, 
			&e->pl[e->fds[e->waitingpl[i]].pl]);
		e->nbpl++;
		e->tnbpl++;
		e->teams[e->fds[e->waitingpl[i]].team].nbpl++;
		e->wpl--;
	}
	else if (e->teams[tmp].forknb > 0)
	{
		e->fds[e->waitingpl[i]].pl
		= e->teams[tmp].fork[e->teams[tmp].forknb - 1];
		new_tpl(e, e->waitingpl[i],
			0, &e->pl[e->teams[tmp].fork[e->teams[tmp].forknb - 1]]);
		e->teams[tmp].forknb--;
		e->wpl--;
	}
}

void		serv_update__(t_env *e, int tmp, int i, time_t tloc)
{
	i = e->wpl - 1;
	while (i >= 0)
	{
		if (e->forknb > 0 && e->fds[e->waitingpl[i]].pl >= -1)
		{
			e->fds[e->waitingpl[i]].pl = e->fork[e->forknb];
			e->pl[e->fork[e->forknb]].cs = e->waitingpl[i];
			e->wpl--;
			e->forknb--;
		}
		else if (!e->fds[e->waitingpl[i]].noteam && e->fds[e->waitingpl[i]].pl 
			>= -1)
		{
			tmp = e->fds[e->waitingpl[i]].team;
			check_wpl(e, i, tmp);
		}
		i--;
	}
	if (time(&tloc) - e->generation_timer > (GENE_TIME / e->time_unit))
	{
		rand_generate(e);
		e->generation_timer = time(&tloc);
	}
	return ;
}

void		serv_update_(t_env *e, int tmp, int i, time_t tloc)
{
	i = e->nbegg - 1;
	while (i >= 0)
	{
		if (e->eggs[i].updated)
		{
			g_send_egg(e->eggs[i], e->eggs[i].pl, i, e);
			e->eggs[i].updated = 0;
		}
		if (time(&tloc) - e->eggs[i].timer >= (EGG_TIME / e->time_unit)
			&& !e->eggs[i].used)
		{
			tloc = 0;
			e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
			e->pl[e->nbpl] = new_pl(e, e->eggs[i], e->nbpl);
			e->pl[e->nbpl].cs = -1;
			e->pl[e->nbpl].updated = 1;
			e->map.map[e->eggs[i].y][e->eggs[i].x].egg--;
			e->nbpl++;
			e->eggs[i].used = 1;
			tloc = 0;
		}
		i--;
	}
	serv_update__(e, tmp, i, tloc);
}

void		serv_update(t_env *e)
{
	int		i;
	time_t	tloc;
	int		tmp;
	int		check;

	i = 0;
	tmp = 0;
	tloc = 0;
	check = 0;
	while (i < e->nbpl)
	{
		if (e->pl[i].alive)
			check_pl(&check, e, i, tmp);
		i++;
	}
	if (check)
		e->general_timer = time(&tloc);
	if (e->map.updated)
		g_send_map(e);
	serv_update_(e, tmp, i, tloc);
}

/*e->fork = (int *)realloc(e->fork, (sizeof(int) * (e->forknb + 1)));
	e->fork[e->forknb] = e->nbpl;
	e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
	e->pl[e->nbpl] = new_pl(e, cs);
	e->pl[e->nbpl].cs = -1;
	e->nbpl++;
	e->forknb++;*/

void		aff_map_(int x, int y, char **toaff, t_env *e)
{
	char	c;
	int		i;

	i = -1;
	while (++i < e->nbpl)
	{
		if (e->pl[i].alive)
			toaff[e->pl[i].y][e->pl[i].x] = e->pl[i].dir + '0';
	}
	x = 0;
	y = 0;
	c = 0;
	y = e->map.ylen;
	while (--y >= 0)
	{
		while (toaff[y][x] != '\0')
		{
			c = toaff[y][x];
			ft_putchar(c);
			ft_putstr("\t");
			x++;
		}
		x = 0;
		ft_putstr("\n");
	}
}

void	aff_map(t_env *e)
{
	char	**toaff;
	int		x;
	int		y;

	x = 0;
	y = 0;
	toaff = (char **)malloc(sizeof(char *) * e->map.ylen);
	while (y < e->map.ylen)
	{
		toaff[y] = (char *)malloc(sizeof(char) * e->map.xlen);
		while (x < e->map.xlen)
		{
			toaff[y][x] = '-';
			toaff[y][x + 1] = '\0';
			x++;
		}
		toaff[y + 1] = '\0';
		x = 0;
		y++;
	}
	ft_putstr("\n");
	aff_map_(x, y, toaff, e);
	sstrmemdel(&toaff);
	ft_putstr("\n");
	return ;
}

void	main_loop(t_env *e)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < e->nbteam)
			i++;
		init_fd(e);
		do_select(e);
		check_fd(e);
		serv_update(e);
		aff_map(e);
	}
}
