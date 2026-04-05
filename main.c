
#include "sdl_test.h"



int main(int argc, char *argv[])
{
	t_data data;
	data.argc = argc;
	data.argv = argv;
    if (init_all(&data))
		return (EXIT_FAILURE);

	user_main(&data);
	
    SDL_DestroyWindow(data.window);
    SDL_Quit();

    return EXIT_SUCCESS;
}