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
	point->x > pa->size[0] ? pa->size[0] = point->x : pa->size[0]; // больший x
	point->x < pa->size[1] ? pa->size[1] = point->x : pa->size[1]; // меньший x
	point->y > pa->size[2] ? pa->size[2] = point->y : pa->size[2]; // больший y
	point->y < pa->size[3] ? pa->size[3] = point->y : pa->size[3]; // меньший y
}

void		search_map_center(t_point ***map, t_paint *pa)
{
	pa->size[0] = -99999999;
	pa->size[1] = 99999999;
	pa->size[2] = -99999999;
	pa->size[3] = 99999999;
	map_pass(map, search_size, pa);
	int 	x;
	int 	y;

	x = ((pa->size[0] - pa->size[1]) / 2) + pa->size[1];
	y = ((pa->size[2] - pa->size[3]) / 2) + pa->size[3];
	pa->mid[0] = (pa->win_x / 2) - x;
	pa->mid[1] = (pa->win_y / 2) - y;
//	printf("123\n");

//	print_line(pa, x, y, 500, 500, 0xFF00FF);
//	print_line(pa, pa->size[0], pa->size[2], pa->size[1], pa->size[3], 0xFF00FF);
//	print_line(pa, pa->size[1], pa->size[2], pa->size[0], pa->size[3], 0xFF00FF);
//
//	print_line(pa, pa->size[1], pa->size[3], pa->size[0], pa->size[3], 0xFF00FF);
//	print_line(pa, pa->size[1], pa->size[3], pa->size[1], pa->size[2], 0xFF00FF);
//
//	print_line(pa, pa->size[0], pa->size[2], pa->size[0], pa->size[3], 0xFF00FF);
//	print_line(pa, pa->size[0], pa->size[2], pa->size[1], pa->size[2], 0xFF00FF);
//	printf("pa->size[0] - %d\npa->size[2] - %d\npa->size[1] - %d\npa->size[3] - %d\nx - %d\ny - %d\npa->mid[0] - %d\npa->mid[1] - %d\n", pa->size[0], pa->size[2], pa->size[1], pa->size[3], x, y, pa->mid[0], pa->mid[1]);
	printf("%d\n", pa->between);
}