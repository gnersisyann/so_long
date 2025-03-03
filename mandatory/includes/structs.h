#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		coins;
}			t_map;

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
#endif