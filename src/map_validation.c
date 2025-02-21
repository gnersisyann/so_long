#include "../includes/so_long.h"

void	check_filename(char *file_name)
{
	char	*tmp;

	tmp = ft_strnstr(file_name, ".ber", ft_strlen(file_name));
	if (!tmp || *(tmp + 4) != '\0')
	{
		perror("Wrong file format\n");
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
			handle_error(data, "invalid exit count\n", 1);
		if (data->map->coins == 0)
			handle_error(data, "invalid coin count\n", 1);
		if (check->player != 1)
			handle_error(data, "invalid player count", 1);
	}
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
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1'
				&& data->map->map[y][x] != 'C' && data->map->map[y][x] != 'E'
				&& data->map->map[y][x] != 'P')
				handle_error(data,
					"Invalid map,valid inputs are '0','1','C','E','P'\n", 1);
			else if (((x == 0 || y == 0 || y == (data->size_y / IMG_H - 1)
						|| x == (data->size_x / IMG_W - 1))
					&& data->map->map[y][x] != '1'))
				handle_error(data, "Invalid walls", 1);
			x++;
		}
		y++;
	}
}
int	check_valid_exit(t_data *data, char **visited, int x, int y)
{
	if (y < 0 || y >= data->size_y / IMG_H || x < 0 || x >= data->size_x
		/ IMG_W)
		return (0); // Проверка границ
	if (visited[y][x] == 'E')
		return (1);
	if (visited[y][x] == '1') // '1' — уже посещена
		return (0);
	visited[y][x] = '1'; // Помечаем клетку как посещенную
	if (check_valid_exit(data, visited, x + 1, y) || check_valid_exit(data,
			visited, x - 1, y) || check_valid_exit(data, visited, x, y + 1)
		|| check_valid_exit(data, visited, x, y - 1))
		return (1);
	return (0);
}

int	check_valid_coins(t_data *data, char **visited, int x, int y, int *counter)
{
	// Проверка границ
	if (y < 0 || y >= data->size_y / IMG_H || x < 0 || x >= data->size_x
		/ IMG_W)
		return (0);
	// Если клетка уже посещена или это стена, возвращаем 0
	if (visited[y][x] == '1')
		return (0);
	// Если нашли монету, увеличиваем счетчик
	if (visited[y][x] == 'C')
		(*counter)++;
	// Помечаем клетку как посещенную
	visited[y][x] = '1';
	// Рекурсивно проверяем все четыре направления
	check_valid_coins(data, visited, x + 1, y, counter);
	check_valid_coins(data, visited, x - 1, y, counter);
	check_valid_coins(data, visited, x, y + 1, counter);
	check_valid_coins(data, visited, x, y - 1, counter);
	// Если количество найденных монет равно общему количеству, возвращаем 1
	if (*counter == data->map->coins)
		return (1);
	return (0);
}

void	check_path(t_data *data)
{
	char **visited;
	int i;
	int len;
	int counter;

	counter = 0;
	i = 0;
	len = ft_strlen(data->map->map[0]);
	visited = ft_calloc((data->size_y / IMG_H) + 1, sizeof(char *));
	if (!visited)
		handle_error(data, "visited calloc error\n", 1);
	while (i < data->size_y / IMG_H)
	{
		visited[i] = ft_strdup(data->map->map[i]);
		if (!visited[i])
			handle_error(data, "visited copy error", 1);
		++i;
	}
	visited[i] = NULL;
	if (!check_valid_exit(data, visited, data->p_x, data->p_y))
	{
		free_double_p(&visited);
		handle_error(data, "exit is not reachable\n", 1);
	}
	i = 0;
	while (i < data->size_y / IMG_H)
	{
		ft_strlcpy(visited[i], data->map->map[i], len);
		if (!visited[i])
			handle_error(data, "visited copy error", 1);
		++i;
	}
	if (!check_valid_coins(data, visited, data->p_x, data->p_y, &counter))
		handle_error(data, "coins are not reachable", 1);
}