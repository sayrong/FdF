/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:27:26 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/02/10 22:29:04 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		zoom(int key, t_fdf *fdf)
{
	if (key == KB_W)
	{
		if (fdf->offset < 50)
		{
			fdf->offset += OFFSET;
			if (fdf->x_z <= 10 && fdf->x_z != 0)
				fdf->x_z += ZZZ;
		}
	}
	else if (key == KB_S)
	{
		if (fdf->offset > 5)
		{
			fdf->offset -= OFFSET;
			if (fdf->x_z >= 2)
				fdf->x_z -= ZZZ;
		}
	}
	return (0);
}

int		high_z(int key, t_fdf *fdf)
{
	if (key == KB_X)
	{
		if (fdf->x_z < 10)
			fdf->x_z += ZZZ;
	}
	else if (key == KB_Z)
	{
		if (fdf->x_z >= 1)
			fdf->x_z -= ZZZ;
	}
	return (0);
}

int		moving(int key, t_fdf *fdf)
{
	if (key == KB_UP)
		fdf->pad_y += PADDING;
	else if (key == KB_DOWN)
		fdf->pad_y -= PADDING;
	else if (key == KB_LEFT)
		fdf->pad_x += PADDING;
	else if (key == KB_RIGHT)
		fdf->pad_x -= PADDING;
	return (0);
}

void	rotate(int key, t_fdf *fdf)
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

int		key_press(int key, t_fdf *fdf)
{
	if (key == KB_ESC)
		finish(fdf);
	zoom(key, fdf);
	high_z(key, fdf);
	moving(key, fdf);
	rotate(key, fdf);
	start_pos(key, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.img_ptr);
	if ((draw_init(fdf)))
		finish(fdf);
	return (0);
}
