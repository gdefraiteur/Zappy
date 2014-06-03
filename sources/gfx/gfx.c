/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/03 22:59:11 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "gfx.h"

int	init_sdl(t_sdl *e)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_error("SDL_Init failed."));
	e->win = SDL_CreateWindow("GFX ZAPPY BETA", SDL_WPU, SDL_WPU, WIDTH, HEIGHT, FS);
	if (e->win == NULL)
		return (ft_error("Can't create window."));
	e->screen = SDL_GetWindowSurface(e->win);
	return (0);
}

void	close_sdl(t_sdl *e)
{
	SDL_FreeSurface(e->screen);
	SDL_DestroyWindow(e->win);
	SDL_Quit();
}

void	draw_bg(t_sdl *e)
{
	int	color;

	color = SDL_MapRGB(e->screen->format, 0xDC, 0x14, 0x3C);
	SDL_FillRect(e->screen, NULL, color);
}

void	draw_menu(t_sdl *e)
{
	int			color;
	SDL_Rect	rcDest;

	rcDest.x = 1620;
	rcDest.y = 0;
	rcDest.w = 300;
	rcDest.h = 1080;
	color = SDL_MapRGB(e->screen->format, 0xCE, 0xCE, 0xCE);
	SDL_FillRect(e->screen, &rcDest, color);
}

void	draw_crap(t_sdl *e)
{
	SDL_Surface	*image;
	SDL_Rect	rcDest;

	image = IMG_Load("img/poo.gif");
	rcDest.x = 0;
	rcDest.y = 0;
	rcDest.w = 50;
	rcDest.h = 50;
	SDL_BlitSurface(image, NULL, e->screen, &rcDest);
}

int	event_listener(SDL_Event *ev, int *quit, t_sdl *e)
{
	while (SDL_PollEvent(ev) != 0)
	{
		if (ev->type == SDL_QUIT)
			*quit = 1;
		else if (ev->type == SDL_KEYDOWN)
		{
			if (ev->key.keysym.sym == KEY_ESC)
				*quit = 1;
			else if (ev->key.keysym.sym == KEY_ENTER)
				draw_crap(e);
			else if (ev->key.keysym.sym == KEY_SPACE)
				draw_bg(e);
		}
	}
	return (0);
}

int	gfx_core(t_sdl *e)
{
	SDL_Event	ev;
	int			quit;

	quit = 0;
	draw_bg(e);
	draw_menu(e);
	while (!quit)
	{
		event_listener(&ev, &quit, e);
		SDL_UpdateWindowSurface(e->win);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_sdl	e;
	
	(void)argc;
	(void)argv;

	ft_putendl("GFX on.");
	init_sdl(&e);
	gfx_core(&e);
	close_sdl(&e);
	return (0);
}
