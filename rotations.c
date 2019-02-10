//
//  rotations.c
//  fdf_tru1
//
//  Created by Babette Alvyn sharp on 10/02/2019.
//  Copyright © 2019 Babette Alvyn sharp. All rights reserved.
//

#include "fdf.h"

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
