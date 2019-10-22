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

static void iso(t_point *point)
{
	int previous_x;
	int previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = (previous_x - previous_y) * cos(0.523599);
	point->y = -point->z + (previous_x + previous_y) * sin(0.523599);
}

void		map_pass(t_point ***map, void f(t_point*))
{
	int 	x;
	int 	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != NULL)
		{
			f(map[y][x]);
			x++;
		}
		y++;
	}
}

void		isometric(t_point ***map)
{
	map_pass(map, iso);
}
