/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 04:10:47 by emeha             #+#    #+#             */
/*   Updated: 2019/10/20 04:56:43 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	drawLine(int x1, int y1, int x2, int y2) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	int error2;

	mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, x2, y2, 0xff0505);
	while(x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, x1, y1, 0xff0505);
		error2 = error * 2;
		if(error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}

int	deal_key(int key, void *param)
{
	t_paint *paint;

	paint = (t_paint*)param;


	int 	x1;
	int 	x2;
	int 	y1;
	int 	y2;

	if (key == 126)
	{
		x1 = 10;
		x2 = 30;
		y1 = 30;
		y2 = 70;
		const int deltaX = abs(x2 - x1);
		const int deltaY = abs(y2 - y1);
		const int signX = x1 < x2 ? 1 : -1;
		const int signY = y1 < y2 ? 1 : -1;
		//
		int error = deltaX - deltaY;
		//
		mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, x2, y2, 0xff0505);
		while(x1 != x2 || y1 != y2)
		{
			mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, x1, y1, 0xff0505);
			const int error2 = error * 2;
			//
			if(error2 > -deltaY)
			{
				error -= deltaY;
				x1 += signX;
			}
			if(error2 < deltaX)
			{
				error += deltaX;
				y1 += signY;
			}
		}
	}


	return (0);
}

int init_window()
{
	t_paint	*paint;

	paint = create_paint();
	paint->mlx_ptr = mlx_init();
	paint->win_ptr = mlx_new_window(paint->mlx_ptr, 500, 500, "fdf");
	mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, 250, 250, 0xff0505);
	mlx_key_hook(paint->win_ptr, deal_key, (void *)paint);
	mlx_loop(paint->mlx_ptr);
	return (0);
}
