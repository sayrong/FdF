#include "fdf.h"

int zoom(int key, t_fdf *fdf)
{
	if (key == KB_W)
	{
		if (fdf->offset < 50)
		{
			fdf->offset += OFFSET;
			if (fdf->xZ <= 10 && fdf->xZ != 0)
				fdf->xZ += ZZZ;
		}
	}
	else if (key == KB_S)
	{
		if (fdf->offset > 5)
		{
			fdf->offset -= OFFSET;
			if (fdf->xZ >= 2)
				fdf->xZ -= ZZZ;
		}
	}
	return (0);
}

int high_z(int key, t_fdf *fdf)
{
	if (key == KB_X)
	{
		if (fdf->xZ < 10)
			fdf->xZ += ZZZ;
	}
	else if (key == KB_Z)
	{
		if (fdf->xZ >= 1)
			fdf->xZ -= ZZZ;
	}
	return (0);
}
int moving(int key, t_fdf *fdf)
{
	if (key == KB_UP)
		fdf->pad_Y += PADDING;
	else if (key == KB_DOWN)
		fdf->pad_Y -= PADDING;
	else if (key == KB_LEFT)
		fdf->pad_X += PADDING;
	else if (key == KB_RIGHT)
		fdf->pad_X -= PADDING;
	return (0);
}

void rotate(int key, t_fdf *fdf)
{
	if (key == KP_2)
		fdf->a += 0.05;
	else if (key == KP_8)
		fdf->a -= 0.05;
	else if (key == KP_4)
		fdf->b -= 0.05;
	else if (key == KP_6)
		fdf->b += 0.05;
	else if (key == KB_I)
		fdf->c += 0.05;
	else if (key == KB_U)
		fdf->c -= 0.05;
}

int start_pos(int key, t_fdf *fdf)
{
	if (key == KB_H)
	{
		fdf->offset = WIN_HEIGHT / (2 * fdf->lines) + 2;
		fdf->pad_X = WIN_WIDTH / 2;
		fdf->pad_Y = WIN_HEIGHT / 6;
		fdf->xZ = 3;
		fdf->a = 0;
		fdf->b = 0;
		fdf->c = 0;
	}
	return (0);
}

int key_press(int key, t_fdf *fdf)
{
	if (key == KB_ESC)
		exit(0);
	zoom(key, fdf);
	high_z(key, fdf);
	moving(key, fdf);
	rotate(key, fdf);
	start_pos(key, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.img_ptr);
	draw_init(fdf);
	return (0);
}
