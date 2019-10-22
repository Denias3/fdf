/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_struct_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:37:14 by emeha             #+#    #+#             */
/*   Updated: 2019/10/19 20:37:15 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	*create_point(void)
{
	t_point *po;

	po = (t_point*)malloc(sizeof(t_point));
	po->x = -1;
	po->y = 0;
	po->z = -1;
	po->color = NULL;
	po->next = NULL;
	return (po);
}

t_val	*create_val(t_point *po)
{
	t_val *val;

	val = (t_val*)malloc(sizeof(t_val));
	val->max_x = -1;
	val->max_y = -1;
	val->end_point = po;
	val->start_point = po;
	return (val);
}

t_paint	*create_paint(t_val *val, t_point ***map)
{
	t_paint *paint;

	paint = (t_paint*)malloc(sizeof(t_paint));
	paint->map = map;
	paint->val = val;
	paint->win_x = 2000;
	paint->win_y = 1000;
	paint->mlx_ptr = NULL;
	paint->win_ptr = NULL;
	paint->h_indent = 0;
	paint->u_indent = 0;
	paint->field_width = 0;
	paint->field_height = 0;
	paint->between = 0;
	paint->mid_x = (int*)malloc(sizeof(int) * 3);
	paint->mid_x[0] = 0;
	paint->mid_x[1] = 99999999;
	paint->mid_x[2] = 0;
	paint->mid_y = (int*)malloc(sizeof(int) * 3);
	paint->mid_y[0] = 0;
	paint->mid_y[1] = 99999999;
	paint->mid_x[2] = 0;
	return (paint);
}
