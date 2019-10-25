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
	else if ((keycode == 24 || keycode == 69))
	{
		approach(paint);
		starting_position(paint->val->start_point, paint);
		twist_map_x_y(paint, paint->val->start_point, paint->val);
	}
	else if ((keycode == 27 || keycode == 78) && paint->between > 0)
	{
		distance(paint);
		starting_position(paint->val->start_point, paint);
		twist_map_x_y(paint, paint->val->start_point, paint->val);
	}
	else if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
	{
		if (keycode == 13)
			paint->cos_sin_x += 0.174533;
		else if (keycode == 1)
			paint->cos_sin_x -= 0.174533;
		else if (keycode == 0)
			paint->cos_sin_y += 0.174533;
		else if (keycode == 2)
			paint->cos_sin_y -= 0.174533;
		replace_op(paint->val->start_point, paint->val->static_point);
		make_accurate(paint, paint->val);
		starting_position(paint->val->start_point, paint);
		twist_map_x_y(paint, paint->val->start_point, paint->val);
	}
	else if (keycode == 12 || keycode == 14)
	{
		if (keycode == 12)
			paint->cos_sin_z += 0.174533;
		else if (keycode == 14)
			paint->cos_sin_z -= 0.174533;
		replace_op(paint->val->start_point, paint->val->static_point);
		make_accurate(paint, paint->val);
		starting_position(paint->val->start_point, paint);
		twist_map_z(paint, paint->val->start_point, paint->val);
	}
	mlx_clear_window(paint->mlx_ptr, paint->win_ptr);
	draw_map(paint->map, paint);
	return (0);
}
