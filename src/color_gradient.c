/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balvyn-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:11:01 by balvyn-s          #+#    #+#             */
/*   Updated: 2019/02/10 22:12:30 by balvyn-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_point *current, t_point *start, t_point *end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current->x - start->x > current->y - start->y)
		percentage = percent(start->x, end->x, current->x);
	else
		percentage = percent(start->y, end->y, current->y);
	red = get_light((start->color >> 16) & 0xFF,
					(end->color >> 16) & 0xFF, percentage);
	green = get_light((start->color >> 8) & 0xFF,
			(end->color >> 8) & 0xFF, percentage);
	blue = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	free(current);
	return ((red << 16) | (green << 8) | blue);
}
