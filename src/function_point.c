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
	return (val);
}

t_paint	*create_paint()
{
	t_paint *paint;

	paint = (t_paint*)malloc(sizeof(t_paint));
	paint->x = 250;
	paint->y = 250;
	paint->mlx_ptr = NULL;
	paint->win_ptr = NULL;
	return (paint);
}
