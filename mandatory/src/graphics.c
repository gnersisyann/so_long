#include "../includes/so_long.h"

static void	initialize_helper(t_data **data, int width, int height)
{
	if (!(*data)->img->player_left)
		handle_error(*data, "Error\nPlayer left file not found\n", 1);
	(*data)->img->background = mlx_xpm_file_to_image((*data)->mlx,
			"textures/mandatory/background.xpm", &width, &height);
	if (!(*data)->img->background)
		handle_error(*data, "Error\nbackground file not found\n", 1);
	(*data)->img->wall = mlx_xpm_file_to_image((*data)->mlx,
			"textures/mandatory/wall.xpm", &width, &height);
	if (!(*data)->img->wall)
		handle_error(*data, "Error\nwall file not found\n", 1);
	(*data)->img->coin = mlx_xpm_file_to_image((*data)->mlx,
			"textures/mandatory/coin.xpm", &width, &height);
	if (!(*data)->img->coin)
		handle_error(*data, "Error\ncoin file not found\n", 1);
	(*data)->img->exit = mlx_xpm_file_to_image((*data)->mlx,
			"textures/mandatory/exit.xpm", &width, &height);
	if (!(*data)->img->exit)
		handle_error(*data, "Error\nexit file not found\n", 1);
}

void	initialize(t_data *data)
{
	int	width;
	int	height;

	width = IMG_W;
	height = IMG_H;
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		handle_error(data, "Error\nmalloc error", 1);
	data->img->player_up = mlx_xpm_file_to_image(data->mlx,
			"textures/mandatory/player.xpm", &width, &height);
	if (!data->img->player_up)
		handle_error(data, "Error\nPlayer up file not found\n", 1);
	data->img->player_down = mlx_xpm_file_to_image(data->mlx,
			"textures/mandatory/player.xpm", &width, &height);
	if (!data->img->player_down)
		handle_error(data, "Error\nPlayer down file not found\n", 1);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx,
			"textures/mandatory/player.xpm", &width, &height);
	if (!data->img->player_right)
		handle_error(data, "Error\nPlayer right file not found\n", 1);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx,
			"textures/mandatory/player.xpm", &width, &height);
	initialize_helper(&data, width, height);
}
