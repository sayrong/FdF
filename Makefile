
all:
	sudo gcc -g -Wall -Werror -Wextra fdf.h main.c key_press.c new_life.c mlx.c draw.c ./minilibx/mlx.h -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 ./libft/libft.a ./libft/libft.h ./libft/get_next_line.h -lm
