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

//void		draw_line(t_point *one, t_point *two, t_paint *paint)
//{
//	int 	var[10];
//
//	var[0] = one->x;
//	var[1] = one->y;
//	var[2] = two->x;
//	var[3] = two->y;
//	var[4] = ft_abs(var[2] - var[0]);
//	var[5] = ft_abs(var[3] - var[1]);
//	var[6] = var[0] < var[2] ? 1 : -1;
//	var[7] = var[1] < var[3] ? 1 : -1;
//	var[8] = var[4] - var[5];
//	while(var[0] != var[2] || var[1] != var[3])
//	{
//		mlx_pixel_put(paint->mlx_ptr, paint->win_ptr, var[0], var[1], 0xdf7cad);
//		var[9] = var[8] * 2;
//		if(var[9] > -var[5])
//		{
//			var[8] -= var[5];
//			var[0] += var[6];
//		}
//		if(var[9] < var[4])
//		{
//			var[8] += var[4];
//			var[1] += var[7];
//		}
//	}
//}

int init_window(t_point	***map, t_val *val)
{
	t_paint	*paint;

	paint = create_paint(val, map);
	size_designation(paint, val, 50);
//	paint->mlx_ptr = mlx_init();
//	paint->win_ptr = mlx_new_window(paint->mlx_ptr, paint->win_x, paint->win_y, "fdf");
//	print_line(paint, paint->h_indent, 0, paint->h_indent, paint->win_y, 0x404040);
//	print_line(paint, paint->win_x - paint->h_indent, 0, paint->win_x - paint->h_indent, paint->win_y, 0x404040);
//	print_line(paint, 0, paint->u_indent, paint->win_x, paint->u_indent, 0x404040);
//	print_line(paint, 0, paint->win_y - paint->u_indent, paint->win_x, paint->win_y - paint->u_indent, 0x404040);
	isometric(map, paint);
//	mlx_hook(paint->win_ptr, 2, 0, key_press, (void *)paint);
//	draw_map(map, paint);
//	mlx_loop(paint->mlx_ptr);
	map_val_free(map, paint);
	return (0);
}
