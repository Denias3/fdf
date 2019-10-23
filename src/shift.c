/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 06:47:21 by emeha             #+#    #+#             */
/*   Updated: 2019/10/22 06:47:23 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift_map(t_point *po, int sh)
{
	while (po != NULL)
	{
		if (sh == 1)
			po->y -= 10;
		else if (sh == 2)
			po->x += 10;
		else if (sh == 3)
			po->y += 10;
		else if (sh == 4)
			po->x -= 10;
		po = po->next;
	}
}

void	twist_map_x(t_point *po, int sh)
{
	while (po != NULL)
	{
		if (sh == 0)
		{
			po->y = po->y * cos(0.174533) + po->z * sin(0.174533);
			po->z = -po->y * sin(0.174533) + po->z * cos(0.174533);
		}
		else if (sh == 1)
		{
			po->y = po->y * cos(-0.174533) + po->z * sin(-0.174533);
			po->z = -po->y * sin(-0.174533) + po->z * cos(-0.174533);
		}
		po = po->next;
	}
}
//
//void    rotate_x(int znak, t_fdf *t)
//{
//	int     y;
//	int     x;
//	double  n;
//	double  y0;
//	​
//	n = (znak == 0) ? 0.174533 : -0.174533;
//	y = 0;
//	while (y < t->height)
//	{
//		x = 0;
//		while (x < t->width)
//		{
//			y0 = t->p[y][x].y - t->height / 2;
//			t->p[y][x].y = t->height / 2 + y0 * cos(n) + t->p[y][x].z * sin(n);
//			t->p[y][x].z = -y0 * sin(n) + t->p[y][x].z * cos(n);
//			x++;
//		}
//		y++;
//	}
//}
//​
//void    rotate_y(int znak, t_fdf *t)
//{
//	int     y;
//	int     x;
//	double  n;
//	double  x0;
//	​
//	n = (znak == 0) ? 0.174533 : -0.174533;
//	y = 0;
//	while (y < t->height)
//	{
//		x = 0;
//		while (x < t->width)
//		{
//			x0 = t->p[y][x].x - t->width / 2;
//			t->p[y][x].x = t->width / 2 + x0 * cos(n) + t->p[y][x].z * sin(n);
//			t->p[y][x].z = -x0 * sin(n) + t->p[y][x].z * cos(n);
//			x++;
//		}
//		y++;
//	}
//}
