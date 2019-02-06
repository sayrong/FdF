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

double percent(int start, int end, int current)
{
    double placement;
    double distance;
    
    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_point *current, t_point *start, t_point *end)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;
    
    if (current->x - start->x > current->y - start->y)
        percentage = percent(start->x, end->x, current->x);
    else
        percentage = percent(start->y, end->y, current->y);
    red = get_light((start->color >> 16) & 0xFF, (end->color >> 16) & 0xFF, percentage);
    green = get_light((start->color >> 8) & 0xFF, (end->color >> 8) & 0xFF, percentage);
    blue = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

void swap_points(t_line *l)
{
    ft_swap(&(l->start->x), &(l->end->x));
    ft_swap(&(l->start->y), &(l->end->y));
    ft_swap(&(l->start->color), &(l->end->color));
}

void put_line_low(t_line *l, t_fdf  *fdf)
{
    t_delta new;
    int yi;

    new.dx = l->end->x - l->start->x;
    new.dy = l->end->y - l->start->y;
    yi = 1;
    if (new.dy < 0)
    {
        yi = -1;
        new.dy = -(new.dy);
    }
    new.D = 2 * new.dy -new.dx;
    new.x = l->start->x;
    new.y = l->start->y;
    while (new.x <= l->end->x)
    {
        if (new.x < WIN_WIDTH && new.y < WIN_HEIGHT && new.x > 0 && new.y > 0)
			fdf->img.data[new.y * WIN_WIDTH + new.x] = get_color(get_simple_point(new.x, new.y, 0), l->start, l->end);
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

    new.dx = l->end->x - l->start->x;
    new.dy = l->end->y - l->start->y;
    xi = 1;
    if (new.dx < 0)
    {
        xi = -1;
        new.dx = -(new.dx);
    }
    new.D = 2 * new.dx - new.dy;
    new.x = l->start->x;
    new.y = l->start->y;
    while (new.y <= l->end->y)
    {
		if (new.x < WIN_WIDTH && new.y < WIN_HEIGHT && new.x > 0  && new.y > 0)
        	fdf->img.data[new.y * WIN_WIDTH + new.x] = get_color(get_simple_point(new.x, new.y, 0), l->start, l->end);
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
    if (ft_abs(l->end->y - l->start->y) < ft_abs(l->end->x - l->start->x))
    {
        if (l->start->x > l->end->x)
            swap_points(l);
        put_line_low(l, fdf);
    } else {
        if (l->start->y > l->end->y)
            swap_points(l);
        put_line_high(l, fdf);
    }

}
