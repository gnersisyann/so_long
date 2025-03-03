#include "../includes/so_long.h"

static void	check_map_helper(t_data **data, int x, int y)
{
	if ((*data)->map->map[y][x] != '0' && (*data)->map->map[y][x] != '1'
		&& (*data)->map->map[y][x] != 'C' && (*data)->map->map[y][x] != 'E'
		&& (*data)->map->map[y][x] != 'P')
		handle_error(*data,
			"Error\nInvalid map,valid inputs are '0','1','C','E','P'\n", 1);
	else if (((x == 0 || y == 0 || y == ((*data)->size_y / IMG_H - 1)
				|| x == ((*data)->size_x / IMG_W - 1))
			&& (*data)->map->map[y][x] != '1'))
		handle_error(*data, "Error\nInvalid walls", 1);
}

void	check_map(t_data *data)
{
	int			x;
	int			y;
	t_checker	check;

	y = 0;
	while (y < data->size_y / IMG_H)
	{
		x = 0;
		while (x < data->size_x / IMG_W)
		{
			if (data->map->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			check_validity(data, x, y, &check);
			check_map_helper(&data, x, y);
			x++;
		}
		y++;
	}
}

static void	check_path_helper(t_data **data, char ***visited, int len,
		int *counter)
{
	int	i;
	int	coords[2];

	coords[0] = (*data)->p_x;
	coords[1] = (*data)->p_y;
	i = 0;
	while (i < (*data)->size_y / IMG_H)
	{
		ft_strlcpy((*visited)[i], (*data)->map->map[i], len);
		if (!(*visited)[i])
			handle_error(*data, "Error\nvisited copy error", 1);
		++i;
	}
	if (!check_valid_coins(*data, *visited, coords, counter))
	{
		free_double_p(&(*visited));
		handle_error(*data, "Error\ncoins are not reachable", 1);
	}
	free_double_p(&(*visited));
}

void	check_path(t_data *data)
{
	int		i;
	char	**visited;
	int		len;
	int		counter;

	counter = 0;
	i = 0;
	len = ft_strlen(data->map->map[0]);
	visited = ft_calloc((data->size_y / IMG_H) + 1, sizeof(char *));
	if (!visited)
		handle_error(data, "Error\nvisited calloc error\n", 1);
	while (i < data->size_y / IMG_H)
	{
		visited[i] = ft_strdup(data->map->map[i]);
		if (!visited[i])
			handle_error(data, "Error\nvisited copy error", 1);
		++i;
	}
	visited[i] = NULL;
	if (!check_valid_exit(data, visited, data->p_x, data->p_y))
	{
		free_double_p(&visited);
		handle_error(data, "Error\nexit is not reachable\n", 1);
	}
	check_path_helper(&data, &visited, len, &counter);
}
