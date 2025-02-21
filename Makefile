NAME		=	so_long
HEADER		=	includes/*.h
CC			=	cc
SRCS		=	main.c \
				src/graphics.c \
				src/map_utils.c \
				src/map_validation.c \
				src/player.c \
				src/render.c \
				src/utils.c

MLX_PATH	=	mlx/
LIBFT_PATH	=	libft/
LIBFT		=	libft/libft.a
CFLAGS		=	-g #-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLX_PATH	=	mlx_linux/
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