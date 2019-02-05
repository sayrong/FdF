#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./minilibx/mlx.h"
#include <stdlib.h>
#include "./libft/libft.h"
#include "./libft/get_next_line.h"


typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				chars;
	unsigned long	color;
}					t_fdf;

void ft_printer(t_fdf *fdf);
int ft_put_sizes(t_fdf *fdf);
int line_val(t_fdf *fdf, char *line);
int tab_make(t_fdf *fdf);
int get_cords(t_fdf *fdf);
int tab_filler(t_fdf *fdf);


#endif
