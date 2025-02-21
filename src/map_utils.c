#include "../includes/so_long.h"

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

void	validate_input(t_data *data, char **argv)
{
	char *line;
	int fd;
	int i;
	int len;
	char *newline;

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