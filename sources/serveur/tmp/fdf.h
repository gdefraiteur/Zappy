/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 04:03:01 by gdefrait          #+#    #+#             */
/*   Updated: 2014/04/24 04:03:04 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <string.h>
# include <sys/select.h>
# include <stdlib.h>
# define COEF	(0.08)
# define WINDOW_X 2048
# define WINDOW_Y 1200

typedef struct		s_img
{
	char			*img;
	unsigned long	color;
	int				bits;
	int				sizeline;
	int				endian;
	int				size_x;
	int				size_y;
	int				pos_x;
	int				pos_y;
	void			*ptr;
	void			*win;
	char			*data;
}					t_img;

typedef struct		s_coor
{
	double			x;
	double			y;
	double			len;
	int				h;
	int				res[7];
}					t_coor;

typedef struct		s_cursor
{
	t_coor			pos;
	int				menumode;
	void			*currentitem;
}					t_cursor;

typedef struct		s_ntab
{
	t_coor			*truexy;
	int				*tab;
	int				len;
}					t_ntab;

typedef struct		s_map
{
	t_cursor		cursor;
	char			**lines;
	t_ntab			*map;
	int				len;
	t_img			img;
	unsigned long	tmpcolor;
	double			tmpdir;
}					t_map;

typedef struct		s_gegg
{
	t_coor			pos;
	int				alive;
}					t_gegg;

typedef struct		s_gpl
{
	time_t			bct;
	char			*bc;
	t_coor			pos;
	int				dir;
	int				alive;
	int				*inv;
}					t_gpl;

typedef struct		s_env
{
	t_map			mapp;
	t_gpl			*gpls;
	int				nbgpl;
	t_gegg			*geggs;
	int				nbgegg;
	int				tuset;
	int				mszset;
}					t_env;
/*
void					new_gpl(char *buf, t_env *e)
{
	e->gpls[e->nbpgl].pos.x = getnumb(buf, 1, ' ');
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
*/
double				square(double nbr);
int					ft_sstrlen(char **sstr);
t_map				draw_line(t_coor c1, t_coor c2, t_map map, int j);
t_map				draw_lines(int y, t_map map);
t_map				affmap(t_map map);
t_coor				normalize(t_coor c1, t_coor c2);
t_map				getmap(char *file);
t_map				getpoints(t_map map);
t_ntab				get_tab(char *line, int y);
t_img				pixel_put(t_img img, int x, int y, unsigned long color);
void				put_image(t_img img);
t_img				create_img(t_img img);
int					main(int argc, char **argv);
t_coor				gettruexy(int x, int y, int h, int len);
int					key_watcher(int key);
int					expose(t_map *d);
void				draw_vector(t_coor from, t_coor vector, double len, 
	t_map *map);

#endif
