#include "fdf.h"

int zoom(int key, t_fdf *fdf)
{
	if (key == KB_UP)
		fdf->offset += OFFSET;
	else if (key == KB_DOWN)
	{
		if (fdf->offset > OFFSET)
			fdf->offset -= OFFSET;
	}
	else if (key == KB_RIGHT)
		fdf->xZ += ZZZ;
	else if (key == KB_LEFT)
	{
		if (fdf->xZ > ZZZ)
			fdf->xZ -= ZZZ;
	}
	return (0);
}
int moving(int key, t_fdf *fdf)
{
	if (key == KP_2)
		fdf->pad_Y -= PADDING;
	else if (key == KP_8)
		fdf->pad_Y += PADDING;
	else if (key == KP_4)
		fdf->pad_X += PADDING;
	else if (key == KP_6)
		fdf->pad_X -= PADDING;
	return (0);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KP_2)
		fdf->a += 0.05;
	else if (key == KP_8)
		fdf->a -= 0.05;
	else if (key == KP_4)
		fdf->b-= 0.05;
	else if (key == KP_6)
		fdf->b += 0.05;
	else if (key == KB_W)
		fdf->c += 0.05;
	else if (key == KB_S)
		fdf->c -= 0.05;
}

int key_press(int key, t_fdf *fdf)
{
	zoom(key, fdf);
	moving(key, fdf);
	rotate(key, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.img_ptr);
	draw_init(fdf);
	return (0);
}
