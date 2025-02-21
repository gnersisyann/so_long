#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/* ********** defines to make work easier ********** */

# ifdef __APPLE__ // macOS
#  include "mlx/mlx.h"
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define UARROW 126
#  define LARROW 123
#  define DARROW 125
#  define RARROW 124
# else // Linux (X11)
#  include "mlx_linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define UARROW 65362
#  define LARROW 65361
#  define DARROW 65364
#  define RARROW 65363
# endif

# define IMG_W 32
# define IMG_H 32
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define DIRECTION_UP 8
# define DIRECTION_DOWN 2
# define DIRECTION_LEFT 4
# define DIRECTION_RIGHT 6

/* ***** struct to store the different images ***** */

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
	void	*wall;
	void	*coin;
	void	*exit;
}			t_img;

/* ***** struct to create the map and keep track of the contents ***** */

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		coins;
	// coin count in map
}			t_map;

/* ***** struct to hand all of my programms data between functions ***** */

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		direction;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}			t_data;

typedef struct s_checker
{
	int		player;
	int		exit;
}			t_checker;

/* ********** List the function I am using in the programme ********** */

// void		window_size(t_data *data, char **argv);
// int			ft_key_hook(int keycode, t_data *data);
// void		create_map(t_data *data);
// void		put_object(t_data *data, char *relative_path);
// void		put_player(t_data *data);
// void		validate_input(t_data *data, char **argv, int argc);
// void		put_background(t_data *data);
// void		winner(t_data *data);
// void		ft_move(t_data *data, char position, int direction);
// int			ft_exit(t_data *data);
// void		ft_initializer(t_data *data, t_map *map);
// void		free_double_pointer(t_data *data);
// void		handle_error(t_data *data, char *str, int num);

// // Path checker
// void		ft_putstr_fd(char *s, int fd);
// void		check_path(t_data *data);
// void		check_path_of_collectables(t_data *data, int x, int y);
// int			e_valid_path(t_data *data, int x, int y, char **visited);
// int			c_valid_path(t_data *data, int x, int y, char **visited);

// // helpers
// void		free_double_p(char ***str);
// void		find_px_py(t_data *data);
// void		calloc_failure(char *str);

#endif
