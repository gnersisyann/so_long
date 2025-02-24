#include "../includes/so_long.h"

void	ft_endgame(t_data *data, int state);

void	ft_move(t_data *data, char axis, int move)
{
	int	new_x;
	int	new_y;

	new_x = data->p_x;
	new_y = data->p_y;
	if (axis == 'x')
		new_x += move;
	else
		new_y += move;
	if (data->map->map[new_y][new_x] == '1')
		return ;
	if (data->map->map[new_y][new_x] == 'E')
	{
		if (data->collected != data->map->coins)
			return ;
		else
			ft_endgame(data,1);
	}
	if (data->map->map[new_y][new_x] == 'M')
	{
			ft_endgame(data,0);
	}
	if (data->map->map[new_y][new_x] == '0'
		|| data->map->map[new_y][new_x] == 'C')
	{
		if (data->map->map[new_y][new_x] == 'C')
			++data->collected;
		data->map->map[data->p_y][data->p_x] = '0';
		data->p_x = new_x;
		data->p_y = new_y;
		data->map->map[data->p_y][data->p_x] = 'P';
		++data->counter;
		ft_render_next_frame(data);
	}
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W || keycode == UARROW)
	{
		data->direction = DIRECTION_UP;
		ft_move(data, 'y', UP);
	}
	else if (keycode == A || keycode == LARROW)
	{
		data->direction = DIRECTION_LEFT;
		ft_move(data, 'x', LEFT);
	}
	else if (keycode == S || keycode == DARROW)
	{
		data->direction = DIRECTION_DOWN;
		ft_move(data, 'y', DOWN);
	}
	else if (keycode == D || keycode == RARROW)
	{
		data->direction = DIRECTION_RIGHT;
		ft_move(data, 'x', RIGHT);
	}
	return (0);
}

void	ft_endgame(t_data *data, int state)
{
	if (state == 1)
		ft_putstr_fd("You won!\n", 1);
	else
		ft_putstr_fd("You lost!\n", 1);
	mlx_destroy_window(data->mlx, data->win);
	
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}
