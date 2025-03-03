NAME		=	so_long
NAME_BONUS	=	so_long_bonus
HEADER		=	mandatory/includes/defines.h \
				mandatory/includes/so_long.h \
				mandatory/includes/structs.h
HEADER_BONUS =	bonus/includes/defines.h \
				bonus/includes/so_long.h \
				bonus/includes/structs.h
CC			=	cc
SRCS		=	mandatory/main.c \
				mandatory/src/graphics.c \
				mandatory/src/map_utils.c \
				mandatory/src/map_validation.c \
				mandatory/src/player.c \
				mandatory/src/render.c \
				mandatory/src/utils.c
SRCS_BONUS	=	bonus/main.c \
				bonus/src/graphics_bonus.c \
				bonus/src/map_utils_bonus.c \
				bonus/src/map_validation_bonus.c \
				bonus/src/player_bonus.c \
				bonus/src/render_bonus.c \
				bonus/src/utils_bonus.c

MLX_PATH	=	mlx
LIBFT_PATH	=	libft/
LIBFT		=	libft/libft.a
CFLAGS		=	-g -Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLX_PATH	=	mlx_linux
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
endif

all:	subsystems $(NAME)

bonus:	subsystems $(NAME_BONUS)

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME_BONUS)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus/%.o: bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	$(RM) -f $(OBJS) $(OBJS_BONUS)

fclean:	clean
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	$(RM) -f $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY:	all clean fclean re
