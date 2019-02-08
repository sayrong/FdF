
all:
	sudo gcc -g -Wall -Werror -Wextra main.c key_press.c colors.c new_life.c mlx.c draw.c -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 ./libft/libft.a  -lm
