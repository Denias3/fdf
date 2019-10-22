/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 04:43:48 by fschille          #+#    #+#             */
/*   Updated: 2019/10/22 04:43:50 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void iso(t_point *point, t_paint *pa)
{
	int previous_x;
	int previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = (previous_x - previous_y) * cos(0.523599);
	point->y = -point->z + (previous_x + previous_y) * sin(0.523599);
	point->x > pa->mid_x[0] ? pa->mid_x[0] = point->x : pa->mid_x[0];
	point->x < pa->mid_x[1] ? pa->mid_x[1] = point->x : pa->mid_x[1];
	point->y > pa->mid_y[0] ? pa->mid_y[0] = point->y : pa->mid_y[0];
	point->y < pa->mid_y[1] ? pa->mid_y[1] = point->y : pa->mid_y[1];
}

static void plus(t_point *point, t_paint *pa)
{
	point->x += pa->mid_x[2];
	point->y += pa->mid_y[2];
}

void		map_pass(t_point ***map, void f(t_point*, t_paint*), t_paint *pa)
{
	int 	x;
	int 	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != NULL)
		{
			f(map[y][x], pa);
			x++;
		}
		y++;
	}
}

void		isometric(t_point ***map, t_paint *pa)
{
	map_pass(map, iso, pa);
	int 	x;
	int 	y;

	x = ((pa->mid_x[0] - pa->mid_x[1]) / 2) + pa->mid_x[1];
	y = ((pa->mid_y[0] - pa->mid_y[1]) / 2) + pa->mid_y[1];
	pa->mid_x[2] = (pa->win_x / 2) - x;
	pa->mid_y[2] = (pa->win_y / 2) - y;

	map_pass(map, plus, pa);
//	mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 0xFF00FF);
//	print_line(pa, x, y, 850, 600, 0xFF00FF);
//	print_line(pa, pa->mid_x[0], pa->mid_y[0], pa->mid_x[1], pa->mid_y[1], 0xFF00FF);
//	print_line(pa, pa->mid_x[1], pa->mid_y[0], pa->mid_x[0], pa->mid_y[1], 0xFF00FF);

	printf("pa->mid_x[0] - %d\npa->mid_y[0] - %d\npa->mid_x[1] - %d\npa->mid_y[1] - %d\nx - %d\ny - %d\npa->mid_x[2] - %d\npa->mid_y[2] - %d\n", pa->mid_x[0], pa->mid_y[0], pa->mid_x[1], pa->mid_y[1], x, y, pa->mid_x[2], pa->mid_y[2]);
}
