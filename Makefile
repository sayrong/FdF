NAME = fdf

SRC = color_gradient.c colors.c draw.c helper_first.c helper_second.c key_press.c main.c mlx.c new_life.c rotations.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

MLX = ./minilibx_macos/
MLX_LNK = -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

FT = ./libft/
FT_LNK = -L ./libft -lft

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I $(MLX) -I $(FT) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(FT)
	make -C $(MLX)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT) fclean

re: fclean all
