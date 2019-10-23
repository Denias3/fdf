/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 05:24:31 by emeha             #+#    #+#             */
/*   Updated: 2019/10/22 05:24:33 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int  key_press(int keycode, void *param)
{
	t_paint *paint;

	paint = param;
	if (keycode == 126)
		shift_map(paint, 1);
	else if (keycode == 124)
		shift_map(paint, 2);
	else if (keycode == 125)
		shift_map(paint, 3);
	else if (keycode == 123)
		shift_map(paint, 4);
	else if (keycode == 24 || keycode == 69)
	{
		approach(paint);
		starting_position(paint->val->start_point, paint);
		isometric(paint->map, paint);
	}
	else if (keycode == 27 || keycode == 78)
	{
		distance(paint);
		starting_position(paint->val->start_point, paint);
		isometric(paint->map, paint);
	}
	else if (keycode == 13)
		twist_map_x(paint, paint->val->start_point, 0, paint->val);
	else if (keycode == 1)
		twist_map_x(paint, paint->val->start_point, 1, paint->val);
	else if (keycode == 0)
		twist_map_y(paint, paint->val->start_point, 0, paint->val);
	else if (keycode == 2)
		twist_map_y(paint, paint->val->start_point, 1, paint->val);
	mlx_clear_window(paint->mlx_ptr, paint->win_ptr);
	draw_map(paint->map, paint);
	return (0);
}
