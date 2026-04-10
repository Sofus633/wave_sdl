#ifndef DRAW_FUNC_H
#define DRAW_FUNC_H
#include <SDL2/SDL.h>
#include "../vector_2/vector_2.h"

typedef struct t_face{
	t_vec2 pos;
	t_vec2  vel;
	t_vec2 points[4];
	double		z_pos;
	double		z_vel;
}	t_face;

typedef struct s_wave_sim{
	int nb_faces;
	struct t_face *faces;
	struct t_face **faces_2d;
} t_wave_sim;

typedef struct s_data{
	int			argc;
	char 		**argv;
	SDL_Window	*window;
	SDL_Renderer *renderer;
	t_wave_sim	*sim;
	bool mousepress;
	bool quit;
	SDL_Event event;
} t_data;



void draw_face(t_face face, t_data data);

#endif
