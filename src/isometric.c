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

static void	iso(t_point *point, t_paint *pa)
{
	double	previous_x;
	double	previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = (previous_x - previous_y) * cos(0.523599);
	point->y = -point->z + (previous_x + previous_y) * sin(0.523599);
	pa->shift_x--;
	pa->shift_x++;
}

void		plus(t_point *point, t_paint *pa)
{
	point->x += pa->mid[0] + pa->shift_x;
	point->y += pa->mid[1] + pa->shift_y;
}

void		map_pass(t_point ***map, void f(t_point*, t_paint*), t_paint *pa)
{
	int	x;
	int	y;

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
}
