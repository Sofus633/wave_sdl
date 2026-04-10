#include "user.h"

int set_color(int z_pos){
	//printf("%d\n", z_pos%256)
	return (z_pos%256);
}
void draw_faces(t_data *data){
	SDL_SetRenderDrawColor(data->renderer,
				100,
				0,
				0,
				255);
	for (int i = 0; i < data->sim->nb_faces-1; i++){
		draw_face(data->sim->faces[i], *data);
	}
}

void draw_faces_2d(t_data *data){
	for (int i = 0; i < data->sim->nb_faces-1; i++){
		for (int y = 0; y < data->sim->nb_faces-1; y++){
			SDL_SetRenderDrawColor(data->renderer,
				set_color(data->sim->faces_2d[i][y].z_pos),
				(int)(data->sim->faces_2d[i][y].z_pos - 255) % 256,
				10 + (int)(data->sim->faces_2d[i][y].z_pos - (255*2)) % 256,
				255);
			if (i == 100 && (y < 100 || y > 110))
			{
				SDL_SetRenderDrawColor(data->renderer,
				set_color(data->sim->faces_2d[i][y].z_pos),
				(int)(data->sim->faces_2d[i][y].z_pos - 255) % 256,
				115 + (int)(data->sim->faces_2d[i][y].z_pos - (255*2)) % 256,
				255);
			}
			draw_face(data->sim->faces_2d[i][y], *data);
		}
	}
}


