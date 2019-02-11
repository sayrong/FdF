/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:28:12 by jfrankly          #+#    #+#             */
/*   Updated: 2019/02/11 18:30:59 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		define_color(int z)
{
	if (z <= 0)
		return (0x008000);
	if (z < 10)
		return (0x8B4513);
	return (0xffffff);
}

t_point	*get_simple_point(int x, int y, int z)
{
	t_point *new;

	if ((new = (t_point*)malloc(sizeof(t_point))))
	{
		new->x = x;
		new->y = y;
		new->z = z;
		new->color = define_color(z);
	}
	return (new);
}

t_point	*get_point(int x, int y, t_fdf *fdf)
{
	t_point *new;

	new = (t_point *)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	new->z = fdf->map[fdf->n][fdf->m] * fdf->x_z;
	rotate_x(&new->y, &new->z, fdf->a);
	rotate_y(&new->x, &new->z, fdf->b);
	rotate_z(&new->x, &new->y, fdf->c);
	if (!(fdf->color[fdf->n][fdf->m]))
		new->color = define_color(fdf->map[fdf->n][fdf->m]);
	else
		new->color = fdf->color[fdf->n][fdf->m];
	iso(&(new->x), &(new->y), new->z, fdf);
	return (new);
}

t_line	*get_t_line(t_point *f, t_point *s)
{
	t_line *new;

	if ((new = (t_line *)malloc(sizeof(t_line))))
	{
		new->start = f;
		new->end = s;
	}
	return (new);
}
