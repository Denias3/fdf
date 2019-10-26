/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_approach.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 05:27:31 by emeha             #+#    #+#             */
/*   Updated: 2019/10/22 05:27:32 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	replace_op(t_point *replace, t_point *new)
{
	while (replace != NULL)
	{
		replace->x = new->x;
		replace->z = new->z;
		replace->y = new->y;
		replace = replace->next;
		new = new->next;
	}
}

void	replace_op_st(t_point *po, t_point *new, t_paint *paint)
{
	int y0;
	int x0;

	while (po != NULL)
	{
		po->x = new->x;
		po->z = new->z;
		po->y = new->y;
		po->x = paint->between * po->x;
		po->y = paint->between * po->y;
		po->z = paint->between * po->z;
		po->x += paint->h_indent;
		po->y += paint->u_indent;
		x0 = po->x - paint->val->max_x / 2;
		y0 = po->y - paint->val->max_y / 2;
		po->y = paint->val->max_y / 2 + y0 * cos(paint->cos_sin_x) + po->z * sin(paint->cos_sin_x);
		po->z = -y0 * sin(paint->cos_sin_x) + po->z * cos(paint->cos_sin_x);
		po->x = paint->val->max_x / 2 + x0 * cos(paint->cos_sin_y) + po->z * sin(paint->cos_sin_y);
		po->z = -x0 * sin(paint->cos_sin_y) + po->z * cos(paint->cos_sin_y);
		x0 = po->x - paint->val->max_x / 2;
		y0 = po->y - paint->val->max_y / 2;
		po->x = paint->val->max_x / 2 + x0 * cos(paint->cos_sin_z) - y0 * sin(paint->cos_sin_z);
		po->y = paint->val->max_x / 2 + x0 * sin(paint->cos_sin_z) + y0 * cos(paint->cos_sin_z);
		po = po->next;
		new = new->next;
	}
	search_map_center(paint->map, paint);
	map_pass(paint->map, plus, paint);
}

void	distance(t_paint *paint)
{
	if (paint->between > 1)
		paint->between = paint->between - 1;
	replace_op_st(paint->val->start_point, paint->val->init_point, paint);
	if (paint->iso)
		isometric(paint->map, paint);
}

void	approach(t_paint *paint)
{
	paint->between = paint->between + 1;
	replace_op_st(paint->val->start_point, paint->val->init_point, paint);
	if (paint->iso)
		isometric(paint->map, paint);
}