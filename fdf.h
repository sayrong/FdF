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
#include <math.h>
#include "keys.h"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define PADDING 20
# define OFFSET 5
# define ZZZ 2

typedef struct         s_point
{
    int x;
    int y;
    int z;
    int color;
}                      t_point;

typedef struct        s_delta
{
    int dx;
    int dy;
    int D;
    int x;
    int y;
}                    t_delta;

typedef struct       s_line
{
    t_point         *start;
    t_point         *end;
}                   t_line;

typedef struct      s_img
{
    void            *img_ptr;
    int             *data;
    int             size_l;
    int             bpp;
    int             endian;
}                   t_img;

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
    int				offset;
	int				xZ;
	int				pad_X;
	int				pad_Y;
    t_img           img;
}					t_fdf;

void ft_printer(t_fdf *fdf);
int ft_put_sizes(t_fdf *fdf);
int line_val(t_fdf *fdf, char *line);
int tab_make(t_fdf *fdf);
int get_cords(t_fdf *fdf);
int tab_filler(t_fdf *fdf);
int key_press(int key, t_fdf *fdf);
void put_line(t_line *l, t_fdf  *fdf);
void setup_mlx(t_fdf *fdf);
void draw_init(t_fdf *fdf);
int win_close(void *param);
void	draw_background(t_fdf *fdf);

t_point *get_simple_point(int x, int y, int z);

#endif
