#include "../includes/so_long.h"

void	free_double_pointer(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
		i++;
	while (i > 0)
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
	while (i > 0)
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

void	free_mlx_images(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->img->player_up);
	mlx_destroy_image(data->mlx, data->img->player_down);
	mlx_destroy_image(data->mlx, data->img->player_left);
	mlx_destroy_image(data->mlx, data->img->player_right);
	mlx_destroy_image(data->mlx, data->img->background);
	mlx_destroy_image(data->mlx, data->img->wall);
	mlx_destroy_image(data->mlx, data->img->exit);
	mlx_destroy_image(data->mlx, data->img->enemy);
	for (i = 0; i < 10; i++)
		mlx_destroy_image(data->mlx, data->img->coin[i]);
}

int	ft_exit(t_data *data)
{
	free_mlx_images(data);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	printf("\nWINDOW CLOSED\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}
