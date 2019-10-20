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

int	deal_key(int key, void *param)
{
	t_paint *paint;

	paint = (t_paint*)param;
	if (key == 126)
		(paint->y)--;
	else if (key == 125)
		(paint->y)++;
	else if (key == 124)
		(paint->x)++;
	else if (key == 123)
		(paint->x)--;

	printf("x - %d\t\ty - %d\n", paint->x, paint->y);
	mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, paint->x, paint->y, 0xff0505);
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
