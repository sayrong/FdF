//
//  mlx.c
//  fdf_true
//
//  Created by Dima on 05/02/2019.
//  Copyright © 2019 Dima_Skorokhodov. All rights reserved.
//

#include "fdf.h"

void iso(int *x, int *y, int z, t_fdf *fdf)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599) + fdf->pad_X;
	*y = -z + (previous_x + previous_y) * sin(0.523599) + fdf->pad_Y;
}

int define_color(int z)
{
    if (z <= 0)
        return 0x008000;
    if (z < 10)
        return 0x8B4513;
    return 0xffffff;
}

t_point *get_simple_point(int x, int y, int z)
{
    t_point *new = (t_point*)malloc(sizeof(t_point));
    new->x = x;
    new->y= y;
    new->z = z;
    new->color = define_color(z);
    return new;
}

void	rotate_x(int *y, int *z, double a)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(a) + *z * sin(a);
	*z = -previous_y * sin(a) + *z * cos(a);
}

void	rotate_y(int *x, int *z, double b)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(b) + *z * sin(b);
	*z = -previous_x * sin(b) + *z * cos(b);
}

void	rotate_z(int *x, int *y, double c)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(c) - previous_y * sin(c);
	*y = previous_x * sin(c) + previous_y * cos(c);
}

t_point *get_point(int x, int y, int z, t_fdf *fdf)
{
	t_point *new = (t_point *)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	new->z = z * fdf->xZ;
	rotate_x(&new->y, &new->z, fdf->a);
	rotate_y(&new->x, &new->z, fdf->b);
	rotate_z(&new->x, &new->y, fdf->c);
    new->color = define_color(z);
	iso(&(new->x), &(new->y), new->z, fdf);
	return new;
}

t_line *get_t_line(t_point *f, t_point *s)
{
	t_line *new = (t_line *)malloc(sizeof(t_line));
    new->start = f;
    new->end = s;
	return new;
}

void draw_horizontal(t_fdf *fdf)
{
	int t_x = 0;
	int t_y = 0;
	int n = 0;
	t_point *f_point;
	t_point *s_point;
	while (n != fdf->lines)
	{
		int m = 0;
		while (m != fdf->chars - 1)
		{
			f_point = get_point(t_x, t_y, fdf->map[n][m], fdf);
			t_x += fdf->offset;
			s_point = get_point(t_x, t_y, fdf->map[n][m + 1], fdf);
			put_line(get_t_line(f_point, s_point), fdf);
			m++;
			free(f_point);
			free(s_point);
		}
		t_x = 0;
		t_y += fdf->offset;
		n++;
	}
}

void draw_vertical(t_fdf *fdf)
{
	int t_x = 0;
	int t_y = 0;
	int n;
	int m = 0;
	t_point *f_point;
	t_point *s_point;
	while (m != fdf->chars)
	{
		n = 0;
		while (n != fdf->lines - 1)
		{
			f_point = get_point(t_x, t_y, fdf->map[n][m], fdf);
			t_y += fdf->offset;
			s_point = get_point(t_x, t_y, fdf->map[n + 1][m], fdf);
			put_line(get_t_line(f_point, s_point), fdf);
			n++;
		}
		t_y = 0;
		t_x += fdf->offset;
		m++;
	}
}


int win_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void setup_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	draw_init(fdf);
	mlx_hook(fdf->win, 17, (1L << 17), win_close, fdf);
	mlx_hook(fdf->win, 2, 5, key_press, fdf);
	mlx_loop(fdf->mlx);
}

void draw_init(t_fdf *fdf)
{
	fdf->img.img_ptr = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img.data = (int *)mlx_get_data_addr(fdf->img.img_ptr, &(fdf->img.bpp), &(fdf->img.size_l), &(fdf->img.endian));

	draw_horizontal(fdf);
	draw_vertical(fdf);

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img_ptr, 0, 0);
}
