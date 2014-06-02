#ifndef GFX_H
# define GFX_H

# include "libft.h"

# define SDL_WPU SDL_WINDOWPOS_UNDEFINED
# define FS (SDL_WINDOW_SHOWN)
# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*screen;
}				t_sdl;

#endif
