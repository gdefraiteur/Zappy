/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:39 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/06 18:50:11 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

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
