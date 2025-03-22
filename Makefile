LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
LIBS = -lX11 -lXext -lm -lbsd
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/mandelbrot.c src/helpers.c src/main.c src/ft_atod.c src/julia.c src/events.c
HDRS = fractol.h
OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LIBS)
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
