#include "../includes/so_long.h"

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