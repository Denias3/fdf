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
	map_pass(map, search_size, pa);
	int 	x;
	int 	y;

	x = ((pa->size[0] - pa->size[1]) / 2) + pa->size[1];
	y = ((pa->size[2] - pa->size[3]) / 2) + pa->size[3];
	pa->mid[0] = (pa->win_x / 2) - x;
	pa->mid[1] = (pa->win_y / 2) - y;
}