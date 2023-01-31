CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = -I./libft
GNL = $(wildcard get_next_line/*c)
GNLOBJS = $(GNL:.c=.o)
SRCS = so_long.c so_long_utils.c so_long_check_map.c so_long_move.c so_long_errno.c so_long_free.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -sC LIBFT
	make -sC ./minilibx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./gnl/*.o
	make clean -C ./minilibx
	make fclean -C ./libft

re : fclean all

.PHONY: clean fclean re
