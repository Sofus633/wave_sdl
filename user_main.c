#include "sdl_test.h"



int user_main(t_data *data){
	SDL_SetRenderDrawColor(data->renderer,
							100,
							0,
							0,
							255);


/*	t_face face1 = (t_face){(t_vec2){100, 100},
		{
			{0, 0},
			{0, 10},
			{10, 10},
			{10, 0}
		}
	};*/
	int nb_faces = 20;

	t_face *faces = malloc(sizeof(t_face)* nb_faces);
	for (int i = 0; i < 20; i++){
		faces[i] = (t_face){
			{(i * 20) + 300, 400},
			{0, 0},
		{
			{0, 0},
			{0, 10},
			{10, 10},
			{10, 0}
		}
	};
	}
	faces[1].pos.y += 300;
	for (int y = 0; y < 100; y++){
		SDL_SetRenderDrawColor(data->renderer,
						100,
						0,
						0,
						255);
		for (int i = 0; i < nb_faces-1; i++){
			draw_face(faces[i], *data);
		}

		//printf("%d   ", faces[0].vel.y);
		for (int i = 1; i < nb_faces-2; i++){
			//printf("%d   ", faces[i].vel.y);
			faces[i].vel.y += (((faces[i-1].pos.y + faces[i+1].pos.y) * 0.5) - faces[i].pos.y) * 0.2;
			faces[i].vel.y *= 0.91;
			faces[i].pos.y += faces[i].vel.y;
		}
		//printf("%d   ", faces[8].vel.y);
		//printf("\n");

		SDL_RenderPresent(data->renderer);
		SDL_Delay(100);
		SDL_SetRenderDrawColor(data->renderer,
						0,
						0,
						0,
						255);
		SDL_RenderClear(data->renderer);
	}

	/*faces[2].vel.y += ((faces[1].pos.y + faces[3].pos.y) * 0.5 - faces[2].pos.y) * 0.8;
		faces[2].pos = v_add(faces[2].vel, faces[2].pos);*/
	return 1;
}