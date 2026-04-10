#ifndef USER_H
#define USER_H
# include "../sdl_test.h"
# include "../draw_func/draw_func.h"

#define NB_FACES 200
#define TWODSIM 1

/*struct t_face{
	t_vec2 pos;
	t_vec2  vel;
	t_vec2 points[4];
	double		z_pos;
	double		z_vel;
}	t_face;
*/



void draw_faces(t_data *data);
void draw_faces_2d(t_data *data);

void update_faces_2D(t_data *data);
void update_faces(t_data *faces);

void user_main(t_data *data);

#endif
