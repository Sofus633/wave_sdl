#ifndef SDL_TEST_H
#define SDL_TEST_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector_2/vector_2.h"
#include "draw_func/draw_func.h"
#include "matrices/rotation.h"
#include <stdbool.h>

#define M_PI 3.14159265358979323846
#define WIN_WIDHT  1000
#define WIN_HEIGHT 1000

int user_main(t_data *data);
int user_main_2D(t_data *data);
int init_all(t_data *data);

#endif