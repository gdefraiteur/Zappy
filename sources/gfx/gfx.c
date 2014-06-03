/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/03 16:16:35 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	draw_crap(t_sdl *e)
{
	int	color;
	SDL_Surface	*image;

	color = SDL_MapRGB(e->screen->format, 0xDC, 0x14, 0x3C);
	SDL_FillRect(e->screen, NULL, color);

	image = IMG_Load("img/poo.gif");
	SDL_Rect rcDest = {10, 10, 0, 0};
	SDL_BlitSurface(image, NULL, e->screen, &rcDest);
	SDL_UpdateWindowSurface(e->win);
}

int	quit_listener(SDL_Event *ev, int *quit)
{
	while (SDL_PollEvent(ev) != 0)
	{
		if (ev->type == SDL_QUIT)
			*quit = 1;
	}
	return (0);
}

int	gfx_core(t_sdl *e)
{
	SDL_Event	ev;
	int			quit;

	quit = 0;
	while (!quit)
	{
		quit_listener(&ev, &quit);
		draw_crap(e);
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
