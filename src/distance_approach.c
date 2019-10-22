/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
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

void	distance(t_paint *paint)
{
	replace_op(paint->val->start_point, paint->val->static_point);
	paint->between = paint->between - 1;
	make_accurate(paint, paint->val);
}

void	approach(t_paint *paint)
{
	replace_op(paint->val->start_point, paint->val->static_point);
	paint->between = paint->between + 1;
	make_accurate(paint, paint->val);
}