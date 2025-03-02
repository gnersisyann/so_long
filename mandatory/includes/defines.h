#ifndef DEFINES_H
#define DEFINES_H

/* ********** defines to make work easier ********** */

#ifdef __APPLE__ // macOS
#include "../../mlx/mlx.h"
#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define UARROW 126
#define LARROW 123
#define DARROW 125
#define RARROW 124
#else // Linux (X11)
#include "../../mlx_linux/mlx.h"
#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
#define UARROW 65362
#define LARROW 65361
#define DARROW 65364
#define RARROW 65363
#endif

#define IMG_W 32
#define IMG_H 32
#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1

#define DIRECTION_UP 8
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 4
#define DIRECTION_RIGHT 6

#endif