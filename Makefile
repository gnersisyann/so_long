NAME		=	so_long
HEADER		=	so_long.h
CC			=	cc
SRCS		=	main.c \
				# place_image.c \
				# srcs/so_long.c \
				# srcs/key_manager.c \
				# srcs/maps.c \
				# srcs/validate_map.c \
				# srcs/error.c \
				# srcs/movements.c \
				# srcs/game.c \
				# srcs/free_map.c \
				# srcs/enemy.c \
				# srcs/enemy_move.c \
				# srcs/animation.c

MLX_PATH	=	mlx_linux/
LIBFT_PATH	=	libft/
LIBFT		=	libft/libft.a
CFLAGS		=	-g #-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
endif

all:	subsystems $(NAME)

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(NAME) maps/map11.ber

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean:	clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re