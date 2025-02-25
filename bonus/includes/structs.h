#ifndef STRUCTS_H
#define STRUCTS_H
/* ***** struct to store the different images ***** */

typedef struct s_img {
  void *player_up;
  void *player_left;
  void *player_right;
  void *player_down;
  void *background;
  void *enemy;
  void *wall;
  void *coin[10];
  int current_coin;
  void *exit;
} t_img;

/* ***** struct to create the map and keep track of the contents ***** */

typedef struct s_map {
  char **map;
  void *object;
  int x;
  int y;
  int coins;
  // coin count in map
} t_map;

/* ***** struct to hand all of my programms data between functions ***** */

typedef struct s_data {
  void *mlx;
  void *win;
  int size_x;
  int size_y;
  int p_x;
  int p_y;
  int direction;
  int counter;
  int collected;
  int frame;
  t_map *map;
  t_img *img;
} t_data;

typedef struct s_checker {
  int player;
  int exit;
} t_checker;
#endif