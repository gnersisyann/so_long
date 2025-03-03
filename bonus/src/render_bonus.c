#include "../includes/so_long.h"

void	put_object(t_data *data, int type)
{
	int	coin_frame;

	if (type == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall,
			data->map->x * IMG_W, data->map->y * IMG_H);
	else if (type == 2)
	{
		coin_frame = (data->frame / 4) % 10;
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->coin[coin_frame], data->map->x * IMG_W, data->map->y
			* IMG_H);
	}
	else if (type == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			data->map->x * IMG_W, data->map->y * IMG_H);
	else if (type == 4)
		mlx_put_image_to_window(data->mlx, data->win, data->img->enemy,
			data->map->x * IMG_W, data->map->y * IMG_H);
}

void	put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img->background,
				x, y);
			x += IMG_W;
		}
		y += IMG_W;
	}
}

void	put_player(t_data *data)
{
	if (data->direction == DIRECTION_UP)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			data->map->x * IMG_W, data->map->y * IMG_H);
	else if (data->direction == DIRECTION_DOWN)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_down,
			data->map->x * IMG_W, data->map->y * IMG_H);
	else if (data->direction == DIRECTION_RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			data->map->x * IMG_W, data->map->y * IMG_H);
	else if (data->direction == DIRECTION_LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			data->map->x * IMG_W, data->map->y * IMG_H);
}

void	create_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			put_object(data, 1);
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			put_object(data, 2);
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			put_object(data, 3);
		else if (data->map->map[data->map->y][data->map->x] == 'M')
			put_object(data, 4);
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}

int	ft_render_next_frame(t_data *data)
{
	char *moves_str;
	char *tmp;

	put_background(data);
	create_map(data);

	moves_str = ft_itoa(data->counter);
	tmp = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	mlx_string_put(data->mlx, data->win, (data->size_x / 2) - IMG_W, IMG_H / 2
		- 10, 0x0000ff, tmp);
	free(tmp);

	data->frame++;
	if (data->frame > 1000000)
		data->frame = 0;

	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}