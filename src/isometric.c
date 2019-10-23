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
	point->x > pa->size[0] ? pa->size[0] = point->x : pa->size[0];
	point->x < pa->size[1] ? pa->size[1] = point->x : pa->size[1];
	point->y > pa->size[2] ? pa->size[2] = point->y : pa->size[2];
	point->y < pa->size[3] ? pa->size[3] = point->y : pa->size[3];
}

static void plus(t_point *point, t_paint *pa)
{
	point->x += pa->mid[0];
	point->y += pa->mid[1];
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
	search_map_center(map, pa);
	map_pass(map, plus, pa);
//	mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 0xFF00FF);
//	print_line(pa, x, y, 1000, 500, 0xFF00FF);
//	print_line(pa, pa->size[0], pa->size[2], pa->size[1], pa->size[3], 0xFF00FF);
//	print_line(pa, pa->size[1], pa->size[2], pa->size[0], pa->size[3], 0xFF00FF);

	printf("pa->size[0] - %d\npa->size[2] - %d\npa->size[1] - %d\npa->size[3] - %d\nx - %d\ny - %d\npa->mid[0] - %d\npa->mid[1] - %d\n", pa->size[0], pa->size[2], pa->size[1], pa->size[3], x, y, pa->mid[0], pa->mid[1]);
}
