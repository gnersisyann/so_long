#include "libft/libft.h"
#include "so_long.h"

void	free_double_pointer(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
		i++;
	while (i > 0) // >= changed to >
		free(data->map->map[--i]);
	free(data->map->map);
	free(data->img);
}

void	free_double_p(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		i++;
	i--;
	while (i > 0) // >= changed to >
		free((*str)[--i]);
	free((*str));
}

void	handle_error(t_data *data, char *str, int num)
{
	if (num)
		free_double_pointer(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("\nWINDOW CLOSED\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

void	put_object(t_data *data, int type)
{
	if (type == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall,
			data->map->x * IMG_W, data->map->y * IMG_H);
	else if (type == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img->coin,
			data->map->x * IMG_W, data->map->y * IMG_H);
	else if (type == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
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
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
void		ft_move(t_data *data, char axis, int move);
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

static int	ft_render_next_frame(t_data *data)
/* I made this function to check for keyboard or mouse input */
{
	put_background(data);
	create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

void	ft_endgame(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("\nYOU WON\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

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
			ft_endgame(data);
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
		ft_render_next_frame(data);
	}
}

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

int	ft_line_count(int fd, int size_x)
{
	int		lines;
	char	*line;
	int		len;

	lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			--len;
		if (len != size_x)
		{
			free(line);
			perror("Invalid map (not rectangle)\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		lines++;
	}
	return (lines);
}

void	window_size(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Map opening error\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
	{
		perror("empty file\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(line) - 1;
	data->size_x = len * IMG_W;
	data->size_y = ft_line_count(fd, len) * IMG_H;
	printf("width -> %d\nheigth -> %d\n", data->size_x, data->size_y);
	close(fd);
}

void	initialize(t_data *data)
{
	int	width;
	int	height;

	width = IMG_W;
	height = IMG_H;
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		handle_error(data, "malloc error", 1);
	data->img->player_up = mlx_xpm_file_to_image(data->mlx,
			"textures/ship_up.xpm", &width, &height);
	if (!data->img->player_up)
		handle_error(data, "Error\nPlayer up file not found", 1);
	data->img->player_down = mlx_xpm_file_to_image(data->mlx,
			"textures/ship_down.xpm", &width, &height);
	if (!data->img->player_down)
		handle_error(data, "Error\nPlayer down file not found", 1);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx,
			"textures/ship_right.xpm", &width, &height);
	if (!data->img->player_right)
		handle_error(data, "Error\nPlayer right file not found", 1);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx,
			"textures/ship_left.xpm", &width, &height);
	if (!data->img->player_left)
		handle_error(data, "Error\nPlayer left file not found", 1);
	data->img->background = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &width, &height);
	if (!data->img->background)
		handle_error(data, "Error\nbackground file not found", 1);
	data->img->background = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &width, &height);
	if (!data->img->background)
		handle_error(data, "Error\nbackground file not found", 1);
	data->img->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&width, &height);
	if (!data->img->wall)
		handle_error(data, "Error\nwall file not found", 1);
	data->img->coin = mlx_xpm_file_to_image(data->mlx,
			"textures/collectable.xpm", &width, &height);
	if (!data->img->coin)
		handle_error(data, "Error\ncoin file not found", 1);
	data->img->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&width, &height);
	if (!data->img->exit)
		handle_error(data, "Error\nexit file not found", 1);
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

void	validate_input(t_data *data, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int		len;
	char	*newline;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		handle_error(data, "open error", 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		newline = ft_strjoin(data->map->map[i], line);
		if (!newline)
			handle_error(data, "strjoin error", 1);
		free(data->map->map[i]);
		data->map->map[i] = newline;
		i++;
		free(line);
	}
	close(fd);
	check_map(data);
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
	char	**visited;
	int		i;
	int		len;
	int		counter;

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		perror("Wrong file format\n");
		exit(EXIT_FAILURE);
	}
	check_filename(argv[1]);
	window_size(&data, argv);
	data.map = malloc(sizeof(t_map));
	if (!data.map)
	{
		perror("malloc error for t_map\n");
		exit(EXIT_FAILURE);
	}
	data.map->map = ft_calloc((data.size_y / IMG_H) + 1, sizeof(char *));
	if (!data.map->map)
	{
		perror("calloc error\n");
		free(data.map);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < data.size_y / IMG_H; ++i)
	{
		data.map->map[i] = ft_strdup("");
		if (!data.map->map[i])
			handle_error(&data, "malloc error", 1);
	}
	data.map->map[data.size_y / IMG_H] = NULL;
	data.mlx = mlx_init();
	if (!data.mlx)
		handle_error(&data, "mlx init error", 1);
	initialize(&data);
	validate_input(&data, argv);
	check_path(&data);
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "so_long");
	data.direction = DIRECTION_UP;
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("Error\nLoop fail\n");
	free_double_pointer(&data);
	exit(EXIT_SUCCESS);
}
