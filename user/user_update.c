#include "user.h"

void update_faces_2D(t_data *data){
	double adv;
	for (int y = 1; y <= data->sim->nb_faces-2; y++){
		for (int i = 1; i < data->sim->nb_faces-2; i++){
			if (i == 0)
				adv = (data->sim->faces_2d[y][i+1].z_pos + data->sim->faces_2d[y - 1][i].z_pos + data->sim->faces_2d[y + 1][i].z_pos)/3;
			else if (i == data->sim->nb_faces-1)
				adv = (data->sim->faces_2d[y][i-1].z_pos + data->sim->faces_2d[y - 1][i].z_pos + data->sim->faces_2d[y + 1][i].z_pos)/3;
			else
				adv = (data->sim->faces_2d[y][i-1].z_pos + data->sim->faces_2d[y][i+1].z_pos + data->sim->faces_2d[y+1][i].z_pos + data->sim->faces_2d[y - 1][i].z_pos) / 4;
			data->sim->faces_2d[y][i].z_vel += ((adv) - data->sim->faces_2d[y][i].z_pos) * 0.2;
			data->sim->faces_2d[y][i].z_vel *= 0.91111;
			if (!(y == 100 && (i < 100 || i > 110)))
			{
				data->sim->faces_2d[y][i].z_pos += data->sim->faces_2d[y][i].z_vel;
			}
		}
	}
}

void update_faces(t_data *data){
	double adv;
	for (int i = 1; i <= data->sim->nb_faces-2; i++){
		if (i == 0)
			adv = data->sim->faces[i+1].pos.y;
		else if (i == data->sim->nb_faces-1)
			adv = data->sim->faces[i-1].pos.y;
		else
			adv = (data->sim->faces[i-1].pos.y + data->sim->faces[i+1].pos.y) * 0.5;
		data->sim->faces[i].vel.y += ((adv) - data->sim->faces[i].pos.y) * 0.2;
		data->sim->faces[i].vel.y *= 0.91100;
		data->sim->faces[i].pos.y += data->sim->faces[i].vel.y;
	}
}
