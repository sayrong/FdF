#include "fdf.h"

int zoom(int key, t_fdf *fdf)
{
	if (key == KB_W)
		fdf->offset += OFFSET;
	else if (key == KB_S)
	{
		if (fdf->offset > OFFSET)
			fdf->offset -= OFFSET;
	}
	else if (key == KB_X)
		fdf->xZ += ZZZ;
	else if (key == KB_Z)
	{
		if (fdf->xZ > ZZZ)
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
	else if (key == KB_I)
		fdf->c += 0.05;
	else if (key == KB_U)
		fdf->c -= 0.05;
}

int key_press(int key, t_fdf *fdf)
{
	if (key == KB_ESC)
		exit(0);
	zoom(key, fdf);
	moving(key, fdf);
	rotate(key, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.img_ptr);
	draw_init(fdf);
	return (0);
}
