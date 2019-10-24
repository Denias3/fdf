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

void	shift_map(t_paint *paint, int sh)
{
	t_point *po;

	po = paint->val->start_point;
	if (sh == 1)
		paint->shift_y -= 10;
	else if (sh == 2)
		paint->shift_x += 10;
	else if (sh == 3)
		paint->shift_y += 10;
	else if (sh == 4)
		paint->shift_x -= 10;
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

void	twist_map_x(t_paint *pa, t_point *po, int sh, t_val *val)
{
	double y0;

	while (po != NULL)
	{
		y0 = po->y - val->max_y / 2;
		if (sh == 0)
		{
			po->y = val->max_y / 2 + y0 * cos(0.1) + po->z * sin(0.1);
			po->z = -y0 * sin(0.1) + po->z * cos(0.1);
		}
		else if (sh == 1)
		{
			po->y = val->max_y / 2 + y0 * cos(-0.1) + po->z * sin(-0.1);
			po->z = -y0 * sin(-0.1) + po->z * cos(-0.1);
		}
		po = po->next;
	}
	search_map_center(pa->map, pa);
	map_pass(pa->map, plus, pa);
//	printf("pa->mid[0] - %d\npa->mid[1] - %d\n", pa->mid[0], pa->mid[1]);
}

void	twist_map_y(t_paint *pa, t_point *po, int sh, t_val *val)
{
	double x0;

	while (po != NULL)
	{
		x0 = po->x - val->max_x / 2;
		if (sh == 0)
		{
			po->x = val->max_x / 2 + x0 * cos(0.1) + po->z * sin(0.1);
			po->z = -x0 * sin(0.1) + po->z * cos(0.1);
		}
		else if (sh == 1)
		{
			po->x = val->max_x / 2 + x0 * cos(-0.1) + po->z * sin(-0.1);
			po->z = -x0 * sin(-0.1) + po->z * cos(-0.1);
		}
		po = po->next;
	}
	search_map_center(pa->map, pa);
	map_pass(pa->map, plus, pa);
//	printf("pa->mid[0] - %d\npa->mid[1] - %d\n", pa->mid[0], pa->mid[1]);
}
//void    rotate_y(int znak, t_fdf *t)
//{
//	int     y;
//	int     x;
//	double  n;
//	double  x0;
//	​
//	n = (znak == 0) ? 0.1 : -0.1;
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
//
//void    rotate_x(int znak, t_fdf *t)
//{
//	int     y;
//	int     x;
//	double  n;
//	double  y0;
//	​
//	n = (znak == 0) ? 0.1 : -0.1;
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
//}
