/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:20:41 by fschille          #+#    #+#             */
/*   Updated: 2019/10/23 23:20:49 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void search_size(t_point *point, t_paint *pa)
{
	point->x > pa->size[0] ? pa->size[0] = point->x : pa->size[0];
	point->x < pa->size[1] ? pa->size[1] = point->x : pa->size[1];
	point->y > pa->size[2] ? pa->size[2] = point->y : pa->size[2];
	point->y < pa->size[3] ? pa->size[3] = point->y : pa->size[3];
}

void		search_map_center(t_point ***map, t_paint *pa)
{
	pa->size[0] = -99999999.0;
	pa->size[1] = 99999999.0;
	pa->size[2] = -99999999.0;
	pa->size[3] = 99999999.0;
	map_pass(map, search_size, pa);
	double 	x;
	double 	y;

//	printf("pa->size[0] - %f\npa->size[2] - %f\npa->size[1] - %f\npa->size[3] - %f\n\n", pa->size[0], pa->size[2], pa->size[1], pa->size[3]);
	x = ((pa->size[0] - pa->size[1]) / 2) + pa->size[1];
	y = ((pa->size[2] - pa->size[3]) / 2) + pa->size[3];
	pa->mid[0] = ((double)pa->win_x / 2) - x;
	pa->mid[1] = ((double)pa->win_y / 2) - y;
//	printf("123\n");

	print_line(pa, (int)x, (int)y, 1000, 500, 0xFF00FF);
	print_line(pa, (int)pa->size[0], (int)pa->size[2], (int)pa->size[1], (int)pa->size[3], 0xFF00FF);
	print_line(pa, (int)pa->size[1], (int)pa->size[2], (int)pa->size[0], (int)pa->size[3], 0xFF00FF);
	printf("pa->size[0] - %f\npa->size[2] - %f\npa->size[1] - %f\npa->size[3] - %f\nx - %f\ny - %f\npa->mid[0] - %f\npa->mid[1] - %f\n", pa->size[0], pa->size[2], pa->size[1], pa->size[3], x, y, pa->mid[0], pa->mid[1]);
}