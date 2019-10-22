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
		shift_map(paint->val->start_point, 1, paint->between);
	else if (keycode == 124)
		shift_map(paint->val->start_point, 2, paint->between);
	else if (keycode == 125)
		shift_map(paint->val->start_point, 3, paint->between);
	else if (keycode == 123)
		shift_map(paint->val->start_point, 4, paint->between);
	mlx_clear_window(paint->mlx_ptr, paint->win_ptr);
	draw_map(paint->map, paint);
	return (0);
}
