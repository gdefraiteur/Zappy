/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/04 05:28:10 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "gfx.h"

SDL_Texture	*load_texture(t_env *gfx, char *str)
{
	SDL_Texture	*texture;
	SDL_Surface	*image;

	texture = NULL;
	image = IMG_Load(str);
	texture = SDL_CreateTextureFromSurface(gfx->e.screen, image);
	SDL_FreeSurface(image);
	return (texture);
}

int	init_sdl(t_env *gfx)
{
	int	img_flag;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_error("SDL_Init failed."));
	gfx->e.win = SDL_CreateWindow("GFX ZAPPY", SDL_WPU, SDL_WPU, WIDTH, HEIGHT, FS);
	if (gfx->e.win == NULL)
		return (ft_error("Can't create window."));
	gfx->e.screen = SDL_CreateRenderer(gfx->e.win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(gfx->e.screen, 0xFF, 0xFF, 0xFF, 0xFF);
	img_flag = IMG_INIT_PNG;
	IMG_Init(img_flag);
	gfx->e.view = load_texture(gfx, "img/board.jpg");
	gfx->camera[0] = 0;
	gfx->camera[1] = 0;
	gfx->scroll[0] = 0;
	gfx->scroll[1] = 0;
	gfx->scroll[2] = 0;
	gfx->scroll[3] = 0;
	gfx->s_speed = 1;
	return (0);
}

void	close_sdl(t_env *gfx)
{
	SDL_DestroyWindow(gfx->e.win);
	SDL_Quit();
}

void	draw_menu(t_env *gfx)
{
	SDL_Rect	rcDest;

	rcDest.x = 1620;
	rcDest.y = 0;
	rcDest.w = 300;
	rcDest.h = 1080;
	SDL_SetRenderDrawColor(gfx->e.screen, 0x0E, 0x28, 0x49, 0xFF);
	SDL_RenderDrawRect(gfx->e.screen, &rcDest);
}

void	draw_board(t_env *gfx)
{
	SDL_Rect	rcDest;

	rcDest.x = gfx->camera[0];
	rcDest.y = gfx->camera[1];
	rcDest.w = MAP_W;
	rcDest.h = MAP_H;
	SDL_RenderCopy(gfx->e.screen, gfx->e.view, NULL, &rcDest);
}

void	move_camera(t_env *gfx)
{
	if (gfx->scroll[0] && gfx->camera[1] + gfx->s_speed < 0)
		gfx->camera[1] += gfx->s_speed;
	if (gfx->scroll[1] && gfx->camera[1] > - (MAP_H - HEIGHT - gfx->s_speed))
		gfx->camera[1] -= gfx->s_speed;
	if (gfx->scroll[2] && gfx->camera[0] + gfx->s_speed < 0)
		gfx->camera[0] += gfx->s_speed;
	if (gfx->scroll[3] && gfx->camera[0] > - (MAP_W - WIDTH - gfx->s_speed))
		gfx->camera[0] -= gfx->s_speed;

}

void	mouse_event(t_env *gfx)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	if (y < 150)
	{
		gfx->scroll[0] = 1;
		gfx->s_speed = (150 - y) * 5 / 150;
	}
	else
		gfx->scroll[0] = 0;
	if (y > (HEIGHT - 150))
	{
		gfx->scroll[1] = 1;
		gfx->s_speed = (150 - (HEIGHT - y)) * 5 / 150;
	}
	else
		gfx->scroll[1] = 0;
	if (x < 150)
	{
		gfx->scroll[2] = 1;
		gfx->s_speed = (150 - x) * 5 / 150;
	}
	else
		gfx->scroll[2] = 0;
	if (x > (WIDTH - 150))
	{
		gfx->scroll[3] = 1;
		gfx->s_speed = (150 - (WIDTH - x)) * 5 / 150;
	}
	else
		gfx->scroll[3] = 0;
}

int	event_listener(SDL_Event *ev, int *quit, t_env *gfx)
{
	while (SDL_PollEvent(ev) != 0)
	{
		if (ev->type == SDL_QUIT)
			*quit = 1;
		else if (ev->type == SDL_KEYDOWN)
		{
			if (ev->key.keysym.sym == KEY_ESC)
				*quit = 1;
			else if (ev->key.keysym.sym == KEY_UP)
				gfx->camera[1] -= 1;
			else if (ev->key.keysym.sym == KEY_DOWN)
				gfx->camera[1] += 1;
			else if (ev->key.keysym.sym == KEY_LEFT)
				gfx->camera[0] -= 1;
			else if (ev->key.keysym.sym == KEY_RIGHT)
				gfx->camera[0] += 1;
		}
		else if (ev->type == SDL_MOUSEMOTION)
			mouse_event(gfx);
	}
	return (0);
}

int	gfx_core(t_env *gfx)
{
	SDL_Event	ev;
	int			quit;

	quit = 0;
	while (!quit)
	{
		event_listener(&ev, &quit, gfx);
		SDL_RenderClear(gfx->e.screen);
		move_camera(gfx);
		draw_board(gfx);
		SDL_RenderPresent(gfx->e.screen);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	gfx;
	
	(void)argc;
	(void)argv;

	ft_putendl("GFX on.");
	init_sdl(&gfx);
	gfx_core(&gfx);
	close_sdl(&gfx);
	return (0);
}
