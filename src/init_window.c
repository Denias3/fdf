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

void	drawLine(t_point *one, t_point *two, t_paint *paint)
{
	const int deltaX = abs(two->x - one->x);
	const int deltaY = abs(two->y - one->y);
	const int signX = one->x < two->x ? 1 : -1;
	const int signY = one->y < two->y ? 1 : -1;
	int error = deltaX - deltaY;
	int error2;
	printf("one x(%d) y(%d)\ntwo x(%d) y(%d)\n\n",one->x, one->y, two->x, two->y);

	mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, two->x, two->y, 0xff0505);
	while(one->x != two->x || one->y != two->y)
	{
		mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, one->x, one->y, 0xff0505);
		error2 = error * 2;
		if(error2 > -deltaY)
		{
			error -= deltaY;
			one->x += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			one->y += signY;
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

int init_window(t_point	***map, t_val *val)
{
	t_paint	*paint;

	paint = create_paint();
	size_designation(paint, val);
	paint->mlx_ptr = mlx_init();
	paint->win_ptr = mlx_new_window(paint->mlx_ptr, paint->win_x, paint->win_y, "fdf");

//	mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, 250, 250, 0xff0505);
//	mlx_key_hook(paint->win_ptr, deal_key, (void *)paint);
	drawLine(map[0][0], map[10][10], paint);
	mlx_loop(paint->mlx_ptr);
	return (0);
}
