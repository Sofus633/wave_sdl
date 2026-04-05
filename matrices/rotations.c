#include <math.h>
#include "../vector_2/vector_2.h"

void rotate(double deg, t_vec2 *point)
{
    double x = point->x;
    double y = point->y;

    point->x = (cos(deg) * x) + (-sin(deg) * y);
    point->y = (sin(deg) * x) + (cos(deg) * y);
}
void rotate_mat_2_2(double deg, t_vec2 vec[4]){
	for (int i = 0; i <= 3; i++){
		rotate(deg, &vec[i]);
	}
}