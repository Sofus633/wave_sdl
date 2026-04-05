
#include "vector_2.h"

t_vec2 v_add(t_vec2 v1, t_vec2 v2){
	return ((t_vec2){v1.x + v2.x, v1.y + v2.y});
}