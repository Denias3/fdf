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
	const int deltaX = ft_abs(two->x - one->x);
	const int deltaY = ft_abs(two->y - one->y);
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

void print_to(t_point *po, t_paint *paint)
{
	while (po != NULL)
	{
		mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, po->x, po->y, 0xff0505);
		po = po->next;
	}
}

int init_window(t_point	***map, t_val *val)
{
	t_paint	*paint;

	paint = create_paint();
	size_designation(paint, val);
	paint->mlx_ptr = mlx_init();
	paint->win_ptr = mlx_new_window(paint->mlx_ptr, paint->win_x, paint->win_y, "fdf");
	starting_position(val->start_point, paint);
	printf("h_indent - %d\nu_indent - %d\nfield_width - %d\nfield_height - %d\nbetween- %d\n", paint->h_indent, paint->u_indent, paint->field_width, paint->field_height, paint->between);
	printf("x - %d : y - %d\n", map[0][0]->x, map[0][0]->y);
	print_line(paint, paint->h_indent, 0, paint->h_indent, paint->win_y);
	print_line(paint, paint->win_x - paint->h_indent, 0, paint->win_x - paint->h_indent, paint->win_y);
	print_line(paint, 0, paint->u_indent, paint->win_x, paint->u_indent);
	print_line(paint, 0, paint->win_y - paint->u_indent, paint->win_x, paint->win_y - paint->u_indent);
	print_to(val->start_point, paint);
	mlx_loop(paint->mlx_ptr);
	return (0);
}
