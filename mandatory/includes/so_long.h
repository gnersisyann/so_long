#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "defines.h"
# include "structs.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// utils
void	free_double_pointer(t_data *data);
void	free_double_p(char ***str);
void	handle_error(t_data *data, char *str, int num);
int		ft_exit(t_data *data);
void	free_mlx_images(t_data *data);

// render
void	put_object(t_data *data, int type);
void	put_background(t_data *data);
void	put_player(t_data *data);
void	create_map(t_data *data);
int		ft_render_next_frame(t_data *data);

// player
void	ft_endgame(t_data *data);
void	ft_move(t_data *data, char axis, int move);
int		ft_key_hook(int keycode, t_data *data);

// graphics
void	initialize(t_data *data);

// map validation

void	check_map(t_data *data);

void	check_path(t_data *data);

// map validation utils
void	check_filename(char *file_name);
void	check_validity(t_data *data, int x, int y, t_checker *check);
int		check_valid_exit(t_data *data, char **visited, int x, int y);
int		check_valid_coins(t_data *data, char **visited, int coords[2],
			int *counter);

// map utils
int		ft_line_count(int fd, int size_x);
void	window_size(t_data *data, char **argv);
void	validate_input(t_data *data, char **argv);

#endif
