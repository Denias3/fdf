/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 00:25:34 by fschille          #+#    #+#             */
/*   Updated: 2019/10/22 00:25:36 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void		print_line(t_paint *paint, int x1, int y1, int x2, int y2, int color)
{
	const int deltaX = ft_abs(x2 - x1);
	const int deltaY = ft_abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	int error2;
	printf("one x(%d) y(%d)\ntwo x(%d) y(%d)\n\n",x1, y1, x2, y2);

	mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, x2, y2, color);
	while(x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, x1, y1, color);
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
