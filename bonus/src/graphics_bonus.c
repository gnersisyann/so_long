#include "../includes/so_long.h"

void initialize(t_data *data) {
  int width;
  int height;

  width = IMG_W;
  height = IMG_H;
  data->img = malloc(sizeof(t_img));
  if (!data->img)
    handle_error(data, "Error\nmalloc error", 1);
  data->img->player_up = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/player.xpm", &width, &height);
  if (!data->img->player_up)
    handle_error(data, "Error\nPlayer up file not found", 1);
  data->img->player_down = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/player.xpm", &width, &height);
  if (!data->img->player_down)
    handle_error(data, "Error\nPlayer down file not found", 1);
  data->img->player_right = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/player.xpm", &width, &height);
  if (!data->img->player_right)
    handle_error(data, "Error\nPlayer right file not found", 1);
  data->img->player_left = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/player.xpm", &width, &height);
  if (!data->img->player_left)
    handle_error(data, "Error\nPlayer left file not found", 1);
  data->img->background = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/background.xpm", &width, &height);
  if (!data->img->background)
    handle_error(data, "Error\nbackground file not found", 1);
  data->img->wall = mlx_xpm_file_to_image(data->mlx, "textures/bonus/wall.xpm",
                                          &width, &height);
  if (!data->img->wall)
    handle_error(data, "Error\nwall file not found", 1);

  data->img->coin[0] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin1.xpm", &width, &height);
  if (!data->img->coin[0])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[1] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin2.xpm", &width, &height);
  if (!data->img->coin[1])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[2] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin3.xpm", &width, &height);
  if (!data->img->coin[2])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[3] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin4.xpm", &width, &height);
  if (!data->img->coin[3])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[4] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin5.xpm", &width, &height);
  if (!data->img->coin[4])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[5] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin6.xpm", &width, &height);
  if (!data->img->coin[5])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[6] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin7.xpm", &width, &height);
  if (!data->img->coin[6])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[7] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin8.xpm", &width, &height);
  if (!data->img->coin[7])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[8] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin9.xpm", &width, &height);
  if (!data->img->coin[8])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->coin[9] = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/coin10.xpm", &width, &height);
  if (!data->img->coin[9])
    handle_error(data, "Error\ncoin file not found", 1);

  data->img->exit = mlx_xpm_file_to_image(data->mlx, "textures/bonus/exit.xpm",
                                          &width, &height);
  if (!data->img->exit)
    handle_error(data, "Error\nexit file not found", 1);

  data->img->enemy = mlx_xpm_file_to_image(
      data->mlx, "textures/bonus/enemy.xpm", &width, &height);
  if (!data->img->enemy)
    handle_error(data, "Error\nexit file not found", 1);
}