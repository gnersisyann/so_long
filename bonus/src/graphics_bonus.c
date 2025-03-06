#include "../includes/so_long.h"

static void	initialize_coin(t_data **data, int width, int height)
{
	int			i;
	const char	*coin_files[] = {"textures/bonus/coin1.xpm",
			"textures/bonus/coin2.xpm", "textures/bonus/coin3.xpm",
			"textures/bonus/coin4.xpm", "textures/bonus/coin5.xpm",
			"textures/bonus/coin6.xpm", "textures/bonus/coin7.xpm",
			"textures/bonus/coin8.xpm", "textures/bonus/coin9.xpm",
			"textures/bonus/coin10.xpm"};

	i = 0;
	while (i < 10)
	{
		(*data)->img->coin[i] = mlx_xpm_file_to_image((*data)->mlx,
				(char *)coin_files[i], &width, &height);
		if (!(*data)->img->coin[i])
			handle_error((*data), "Error\ncoin file not found\n", 1);
		++i;
	}
}

static void	initialize_player(t_data **data, int width, int height)
{
	(*data)->img->player_up = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/player.xpm", &width, &height);
	if (!(*data)->img->player_up)
		handle_error((*data), "Error\nPlayer up file not found\n", 1);
	(*data)->img->player_down = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/player.xpm", &width, &height);
	if (!(*data)->img->player_down)
		handle_error((*data), "Error\nPlayer down file not found\n", 1);
	(*data)->img->player_right = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/player.xpm", &width, &height);
	if (!(*data)->img->player_right)
		handle_error((*data), "Error\nPlayer right file not found\n", 1);
	(*data)->img->player_left = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/player.xpm", &width, &height);
	if (!(*data)->img->player_left)
		handle_error((*data), "Error\nPlayer left file not found\n", 1);
}

static void	initialize_other(t_data **data, int width, int height)
{
	(*data)->img->background = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/background.xpm", &width, &height);
	if (!(*data)->img->background)
		handle_error((*data), "Error\nbackground file not found\n", 1);
	(*data)->img->wall = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/wall.xpm", &width, &height);
	if (!(*data)->img->wall)
		handle_error((*data), "Error\nwall file not found\n", 1);
	(*data)->img->exit = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/exit.xpm", &width, &height);
	if (!(*data)->img->exit)
		handle_error((*data), "Error\nexit file not found\n", 1);
	(*data)->img->enemy = mlx_xpm_file_to_image((*data)->mlx,
			"textures/bonus/enemy.xpm", &width, &height);
	if (!(*data)->img->enemy)
		handle_error((*data), "Error\nenemy file not found\n", 1);
}

void	initialize(t_data *data)
{
	int	width;
	int	height;

	width = IMG_W;
	height = IMG_H;
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		handle_error(data, "Error\nmalloc error\n", 1);
	initialize_other(&data, width, height);
	initialize_coin(&data, width, height);
	initialize_player(&data, width, height);
}
