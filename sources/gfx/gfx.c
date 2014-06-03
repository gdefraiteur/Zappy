/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/03 14:25:41 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
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

	color = SDL_MapRGB(e->screen->format, 0xDC, 0x14, 0x3C);
	SDL_FillRect(e->screen, NULL, color);
	SDL_UpdateWindowSurface(e->win);
}

int	main(int argc, char **argv)
{
	t_sdl	e;
	
	(void)argc;
	(void)argv;

	ft_printf("GFX on.");
	init_sdl(&e);
	draw_crap(&e);
	SDL_Delay(2000);
	close_sdl(&e);
	return (0);
}
