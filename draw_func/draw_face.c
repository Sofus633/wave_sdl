#include "draw_func.h"

/*
points in array [0, 1, 2 ,3]
    0             1


	3             2

*/

void draw_face(t_face face, t_data data)
{
	for (int i = 0; i <= 3; i++){
		SDL_RenderDrawLine(data.renderer,
			face.points[i].x       + face.pos.x + (face.points[i].x/2),
			face.points[i].y       + face.pos.y + (face.points[i].y/2),
			face.points[(i+1)%4].x + face.pos.x + (face.points[(i+1)%4].x/2),
			face.points[(i+1)%4].y + face.pos.y + (face.points[(i+1)%4].y/2)
		);
		/*printf("%f %f %f %f\n", face.points[i].x       + face.pos.x,
			face.points[i].y       + face.pos.y,
			face.points[(i+1)%4].x + face.pos.x,
			face.points[(i+1)%4].y + face.pos.y);*/
	}
}