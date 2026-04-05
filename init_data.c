#include "sdl_test.h"

int init_win(t_data *data)
{
	data->window = NULL;
	data->window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640*2, 480*2, SDL_WINDOW_SHOWN);
	if(!data->window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return 1;
    }
	return 0;
}

int init_renderer(t_data *data)
{
	data->renderer = SDL_CreateRenderer(data->window, -1, SDL_RENDERER_ACCELERATED);
	if (!data->renderer)
		return (EXIT_FAILURE);
	return (0);
}


int init_all(t_data *data)
{
	if(0 != SDL_Init(SDL_INIT_VIDEO))
        return ( fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError()), EXIT_FAILURE);
	if (init_win(data))
		return (EXIT_FAILURE);
	if (init_renderer(data))
		return (EXIT_FAILURE);
	return (0);
}
