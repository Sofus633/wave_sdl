#include "user.h"

//to move


t_vec2 get_mouse_pos(void){
	int x = 0;
	int y = 0;
	SDL_GetMouseState(&x, &y);
	return ((t_vec2){x, y});
}

void sim_fill(t_wave_sim *sim){
	(void)sim;
}

void wave_sim_init(t_wave_sim *sim){
	sim->nb_faces = NB_FACES;
	if (TWODSIM)
		sim->faces_2d = malloc(sizeof(t_face *) * sim->nb_faces);
	else
		sim->faces = malloc(sizeof(t_face) * sim->nb_faces);
	sim_fill(sim);
}
void fill_2d(t_wave_sim *sim){
	for (int i = 0; i < sim->nb_faces; i++){
		sim->faces_2d[i] = malloc(sizeof(t_face) * sim->nb_faces);
		for (int y = 0; y < sim->nb_faces; y++){
			//printf("%d %d\n", i, y);
			sim->faces_2d[i][y] = (t_face){
				{(i * 5), (y*5)},
				{0, 0},
			{
				{0, 0},
				{0, 5},
				{5, 5},
				{5, 0}
			}, 
			127,
			0
			};
		}
	}
}

void fill_1d(t_wave_sim *sim){
	for (int i = 0; i < sim->nb_faces; i++){
		sim->faces[i] = (t_face){
			{(i * 3)+2, 600},
			{0, 0},
		{
			{0, 0},
			{0, 2},
			{2, 2},
			{2, 0}
		},
		(double)0,
		(double)0
	};
	}
}

void set_cell_value(int x, int y, t_data *data)
{
	data->sim->faces_2d[y][x].z_pos = 1000; //todo remove magic numbers
}

void manage_events(t_data *data){
	while (SDL_PollEvent(&data->event))
	{
		if(data->event.type == SDL_QUIT)
			data->quit = SDL_FALSE;
		if (data->event.type == SDL_MOUSEBUTTONDOWN){
			data->mousepress = true;
		}
		if (data->event.type == SDL_MOUSEBUTTONUP){
			data->mousepress = false;
		}
	}
	//event triger
	if (data->mousepress){
		t_vec2 pos = get_mouse_pos();
		if (pos.x / 5 < data->sim->nb_faces || pos.y / 5 < data->sim->nb_faces)
			set_cell_value(pos.x / 5, pos.y / 5, data);
	}
}

void main_loop(t_data *data){
	while (data->quit){
		if (TWODSIM){
			update_faces_2D(data);
			draw_faces_2d(data);
		}
		else{
			draw_faces(data);
			update_faces(data);
		}
		manage_events(data);
		SDL_RenderPresent(data->renderer);
		SDL_Delay(10);
		SDL_SetRenderDrawColor(data->renderer,
							0,
							0,
							0,
							255);
		SDL_RenderClear(data->renderer);
	}
}

void user_main(t_data *data)
{
	t_wave_sim sim;

	wave_sim_init(&sim);
	data->sim = &sim;
	if (TWODSIM)
		fill_2d(&sim);
	else
		fill_1d(&sim);
	main_loop(data);
//todo main_loop
}



/*int user_main(t_data *data){
	SDL_SetRenderDrawColor(data->renderer,
							100,
							0,
							0,
							255);


	int nb_faces = 200;

	t_face *faces = malloc(sizeof(t_face)* nb_faces);
	for (int i = 0; i < nb_faces; i++){
		faces[i] = (t_face){
			{(i * 3)+2, 600},
			{0, 0},
		{
			{0, 0},
			{0, 2},
			{2, 2},
			{2, 0}
		},
		(double)0,
		(double)0
	};
	}
	faces[150].pos.y += 500;
	faces[50].pos.y -= 500;

	for (int y = 0; y < 5000; y++){
		draw_faces(nb_faces, faces, data);
		update_faces(nb_faces, faces);

		SDL_RenderPresent(data->renderer);
		SDL_Delay(10);
		SDL_SetRenderDrawColor(data->renderer,
						0,
						0,
						0,
						255);
		SDL_RenderClear(data->renderer);
	}

	return 1;
}



int user_main_2D(t_data *data){
	t_vec2 mousepos;
	SDL_SetRenderDrawColor(data->renderer,
							100,
							0,
							0,
							255);


	t_face face1 = (t_face){(t_vec2){100, 100},
		{
			{0, 0},
			{0, 10},
			{10, 10},
			{10, 0}
		}
	};
	int nb_faces = 200;

	t_face **faces = malloc(sizeof(t_face*)* nb_faces);
	for (int i = 0; i < nb_faces; i++){
		faces[i] = malloc(sizeof(t_face) * nb_faces);
		for (int y = 0; y < nb_faces; y++){
			//printf("%d %d\n", i, y);
			faces[i][y] = (t_face){
				{(i * 5), (y*5)},
				{0, 0},
			{
				{0, 0},
				{0, 5},
				{5, 5},
				{5, 0}
			}, 
			127,
			0
			};
		}
	}
	//faces[100][100].z_pos -= 10000;
	//faces[120][120].z_pos += 10000;
	//faces[300].pos.y -= 500;

	SDL_Event event;
	bool mousepress = false;
	SDL_bool quit = SDL_FALSE;
	while (!quit){
		draw_faces_2d(nb_faces, faces, data);
		update_faces_2D(nb_faces, faces);


		
		if (mousepress){
				mousepos = get_mouse_pos();
				faces[(int)(mousepos.x/5)][(int)(mousepos.y/5)].z_pos = 10000;
		}

		printf("%f, %f \n", mousepos.x, mousepos.y);
		SDL_RenderPresent(data->renderer);
		SDL_Delay(10);
		SDL_SetRenderDrawColor(data->renderer,
						0,
						0,
						0,
						255);
		SDL_RenderClear(data->renderer);
	}

	faces[2].vel.y += ((faces[1].pos.y + faces[3].pos.y) * 0.5 - faces[2].pos.y) * 0.8;
		faces[2].pos = v_add(faces[2].vel, faces[2].pos);
	return 1;
}
*/
