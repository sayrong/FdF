//
//  draw.c
//  fdf_true
//
//  Created by Dima on 05/02/2019.
//  Copyright © 2019 Dima_Skorokhodov. All rights reserved.
//

#include "fdf.h"

int ft_abs(int a) {
    return a > 0 ? a : -a;
}

void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_points(t_line *l)
{
    ft_swap(&(l->x0), &(l->x1));
    ft_swap(&(l->y0), &(l->y1));
}

void put_line_low(t_line *l, t_fdf  *fdf)
{
    t_delta new;
    int yi;

    new.dx = l->x1 - l->x0;
    new.dy = l->y1 - l->y0;
    yi = 1;
    if (new.dy < 0)
    {
        yi = -1;
        new.dy = -(new.dy);
    }
    new.D = 2 * new.dy -new.dx;
    new.x = l->x0;
    new.y = l->y0;
    while (new.x <= l->x1)
    {
        if (new.x < WIN_WIDTH && new.y < WIN_HEIGHT && new.x > 0 && new.y > 0)
			fdf->img.data[new.y * WIN_WIDTH + new.x] = 0xFFFFFF;
        if (new.D > 0)
        {
            new.y += yi;
            new.D -= 2 * new.dx;
        }
        new.D += 2 * new.dy;
        new.x++;
    }
}

void put_line_high(t_line *l, t_fdf  *fdf)
{
    t_delta new;
    int xi;

    new.dx = l->x1 - l->x0;
    new.dy = l->y1 - l->y0;
    xi = 1;
    if (new.dx < 0)
    {
        xi = -1;
        new.dx = -(new.dx);
    }
    new.D = 2 * new.dx - new.dy;
    new.x = l->x0;
    new.y = l->y0;
    while (new.y <= l->y1)
    {
		if (new.x < WIN_WIDTH && new.y < WIN_HEIGHT && new.x > 0  && new.y > 0)
        	fdf->img.data[new.y * WIN_WIDTH + new.x] = 0xFFFFFF;
        if (new.D > 0)
        {
            new.x += xi;
            new.D -= 2 * new.dy;
        }
        new.D += 2 * new.dx;
        new.y++;
    }
}


void put_line(t_line *l, t_fdf  *fdf)
{
    if (ft_abs(l->y1 - l->y0) < ft_abs(l->x1 - l->x0))
    {
        if (l->x0 > l->x1)
            swap_points(l);
        put_line_low(l, fdf);
    } else {
        if (l->y0 > l->y1)
            swap_points(l);
        put_line_high(l, fdf);
    }

}
