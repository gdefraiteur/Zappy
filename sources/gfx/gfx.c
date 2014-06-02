/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/02 18:26:23 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "gfx.h"

int	main(int argc, char **argv)
{
	SDL_Window	*window;
	SDL_Surface	*screen;
	
	window = NULL;
	screen = NULL;
	(void)argc;
	(void)argv;

	ft_printf("GFX on.");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_error("Fuck off."));
	else
	{
		window = SDL_CreateWindow("GFX ZAPPY", SDL_WPU, SDL_WPU, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN);
		if (window == NULL)
			return (ft_error("Can't create window."));
		else
		{
			screen = SDL_GetWindowSurface(window);
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x99, 0x00, 0x00));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
