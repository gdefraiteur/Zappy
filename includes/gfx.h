#ifndef GFX_H
# define GFX_H

# include "libft.h"

# define SDL_WPU SDL_WINDOWPOS_UNDEFINED
# define FS (SDL_WINDOW_SHOWN)
# define WIDTH 1920
# define HEIGHT 1080
# define KEY_ESC 27
# define KEY_ENTER 13
# define KEY_SPACE 32

typedef struct	s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*screen;
}				t_sdl;

#endif
