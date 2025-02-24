#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		perror("Error\nWrong file format\n");
		exit(EXIT_FAILURE);
	}
	check_filename(argv[1]);
	window_size(&data, argv);
	data.map = malloc(sizeof(t_map));
	if (!data.map)
	{
		perror("Error\nmalloc error for t_map\n");
		exit(EXIT_FAILURE);
	}
	data.map->map = ft_calloc((data.size_y / IMG_H) + 1, sizeof(char *));
	if (!data.map->map)
	{
		perror("Error\ncalloc error\n");
		free(data.map);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < data.size_y / IMG_H; ++i)
	{
		data.map->map[i] = ft_strdup("");
		if (!data.map->map[i])
			handle_error(&data, "Error\nmalloc error", 1);
	}
	data.map->map[data.size_y / IMG_H] = NULL;
	data.mlx = mlx_init();
	if (!data.mlx)
		handle_error(&data, "Error\nmlx init error", 1);
	initialize(&data);
	validate_input(&data, argv);
	check_path(&data);
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "so_long");
	data.direction = DIRECTION_UP;
	data.counter = 0;
	data.img->current_coin = 0;
	data.frame = 0;
	ft_render_next_frame(&data);
	mlx_loop_hook(data.mlx, ft_render_next_frame, &data);
	mlx_loop(data.mlx);
	perror("Error\nLoop fail\n");
	free_double_pointer(&data);
	exit(EXIT_SUCCESS);
}
