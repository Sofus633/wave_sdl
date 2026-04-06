#include "sdl_test.h"

void draw_faces(int nb_faces, t_face *faces, t_data *data){
	SDL_SetRenderDrawColor(data->renderer,
				100,
				0,
				0,
				255);
	for (int i = 0; i < nb_faces-1; i++){
		draw_face(faces[i], *data);
	}
}

int set_color(int z_pos){
	//printf("%d\n", z_pos%256)
	return (z_pos%256);
}

void draw_faces_2d(int nb_faces, t_face **faces, t_data *data){
	for (int i = 0; i < nb_faces-1; i++){
		for (int y = 0; y < nb_faces-1; y++){
			SDL_SetRenderDrawColor(data->renderer,
				set_color(faces[i][y].z_pos),
				(int)(faces[i][y].z_pos - 255) % 256,
				10 + (int)(faces[i][y].z_pos - (255*2)) % 256,
				255);
			draw_face(faces[i][y], *data);
		}
	}
}

void update_faces_2D(int nb_faces, t_face **faces){
	double adv;
	for (int y = 1; y <= nb_faces-2; y++){
		//printf("%d   ", faces[i].vel.y);
		for (int i = 1; i < nb_faces-2; i++){
			if (i == 0)
				adv = (faces[y][i+1].z_pos + faces[y - 1][i].z_pos + faces[y + 1][i].z_pos)/3;
			else if (i == nb_faces-1)
				adv = (faces[y][i-1].z_pos + faces[y - 1][i].z_pos + faces[y + 1][i].z_pos)/3;
			else
				adv = (faces[y][i-1].z_pos + faces[y][i+1].z_pos + faces[y+1][i].z_pos + faces[y - 1][i].z_pos) / 4;
			faces[y][i].z_vel += ((adv) - faces[y][i].z_pos) * 0.2;
			faces[y][i].z_vel *= 0.91111;
			faces[y][i].z_pos += faces[y][i].z_vel;
		}
	}
	//printf("%f vel\n", faces[1][1].z_vel);
}

void update_faces(int nb_faces, t_face *faces){
	double adv;
	for (int i = 1; i <= nb_faces-2; i++){
		//printf("%d   ", faces[i].vel.y);
		if (i == 0)
			adv = faces[i+1].pos.y;
		else if (i == nb_faces-1)
			adv = faces[i-1].pos.y;
		else
			adv = (faces[i-1].pos.y + faces[i+1].pos.y) * 0.5;
		faces[i].vel.y += ((adv) - faces[i].pos.y) * 0.2;
		faces[i].vel.y *= 0.91100;
		faces[i].pos.y += faces[i].vel.y;
	}
}

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

	/*faces[2].vel.y += ((faces[1].pos.y + faces[3].pos.y) * 0.5 - faces[2].pos.y) * 0.8;
		faces[2].pos = v_add(faces[2].vel, faces[2].pos);*/
	return 1;
}

t_vec2 get_mouse_pos(void){
	int x = 0;
	int y = 0;
	SDL_GetMouseState(&x, &y);
	return ((t_vec2){x, y});
}

int user_main_2D(t_data *data){
	t_vec2 mousepos;
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


		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				quit = SDL_TRUE;
			if (event.type == SDL_MOUSEBUTTONDOWN){
				mousepress = true;

			}
			if (event.type == SDL_MOUSEBUTTONUP){
				mousepress = false;

			}
		}
		
		if (mousepress){
				mousepos = get_mouse_pos();
				faces[(int)(mousepos.x/5)][(int)(mousepos.y/5)].z_pos = 1000;
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

	/*faces[2].vel.y += ((faces[1].pos.y + faces[3].pos.y) * 0.5 - faces[2].pos.y) * 0.8;
		faces[2].pos = v_add(faces[2].vel, faces[2].pos);*/
	return 1;
}
