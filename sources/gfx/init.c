/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:54:06 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/04 17:54:12 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
