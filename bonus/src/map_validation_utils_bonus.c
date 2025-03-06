#include "../includes/so_long.h"

void	check_filename(char *file_name)
{
	char	*tmp;

	tmp = ft_strnstr(file_name, ".ber", ft_strlen(file_name));
	if (!tmp || *(tmp + 4) != '\0')
	{
		perror("Error\nWrong file format\n");
		exit(1);
	}
}

void	check_validity(t_data *data, int x, int y, t_checker *check)
{
	if (y == 0 && x == 0)
	{
		data->map->coins = 0;
		check->exit = 0;
		check->player = 0;
	}
	if (data->map->map[y][x] == 'E')
		++(check->exit);
	else if (data->map->map[y][x] == 'P')
		++(check->player);
	else if (data->map->map[y][x] == 'C')
		++(data->map->coins);
	if (y == data->size_y / IMG_H - 1 && x == data->size_x / IMG_W - 1)
	{
		if (check->exit == 0 || check->exit > 1)
			handle_error(data, "Error\ninvalid exit count\n", 1);
		if (data->map->coins == 0)
			handle_error(data, "Error\ninvalid coin count\n", 1);
		if (check->player != 1)
			handle_error(data, "Error\ninvalid player count\n", 1);
	}
}

int	check_valid_exit(t_data *data, char **visited, int x, int y)
{
	if (y < 0 || y >= data->size_y / IMG_H || x < 0 || x >= data->size_x
		/ IMG_W)
		return (0);
	if (visited[y][x] == 'E')
		return (1);
	if (visited[y][x] == '1' || visited[y][x] == 'M')
		return (0);
	visited[y][x] = '1';
	if (check_valid_exit(data, visited, x + 1, y) || check_valid_exit(data,
			visited, x - 1, y) || check_valid_exit(data, visited, x, y + 1)
		|| check_valid_exit(data, visited, x, y - 1))
		return (1);
	return (0);
}

int	check_valid_coins(t_data *data, char **visited, int coords[2], int *counter)
{
	int	new_coords[2];

	if (coords[1] < 0 || coords[1] >= data->size_y / IMG_H || coords[0] < 0
		|| coords[0] >= data->size_x / IMG_W)
		return (0);
	if (visited[coords[1]][coords[0]] == '1'
		|| visited[coords[1]][coords[0]] == 'E')
		return (0);
	if (visited[coords[1]][coords[0]] == 'C')
		(*counter)++;
	visited[coords[1]][coords[0]] = '1';
	new_coords[0] = coords[0] + 1;
	new_coords[1] = coords[1];
	check_valid_coins(data, visited, new_coords, counter);
	new_coords[0] = coords[0] - 1;
	new_coords[1] = coords[1];
	check_valid_coins(data, visited, new_coords, counter);
	new_coords[0] = coords[0];
	new_coords[1] = coords[1] + 1;
	check_valid_coins(data, visited, new_coords, counter);
	new_coords[0] = coords[0];
	new_coords[1] = coords[1] - 1;
	check_valid_coins(data, visited, new_coords, counter);
	return (*counter == data->map->coins);
}
