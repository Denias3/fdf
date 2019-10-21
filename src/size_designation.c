/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_designation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:19:37 by fschille          #+#    #+#             */
/*   Updated: 2019/10/21 22:19:50 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define MAX(max_x, max_y) (max_x >= max_y ? max_x : max_y)
#define DD(max, max_x) (max == max_x ? 2 : 1) /* determination of direction */

static void	find_indentation(t_paint *pa, t_val *val, int diraction)
{
	if (diraction == 1)
	{
		pa->field_height = (pa->win_y / 100) * 80;
		pa->u_indent = pa->field_height / 2;
		pa->between = pa->field_height / val->max_y;
		pa->field_width = pa->between * val->max_x;
		pa->h_indent = (pa->win_x - pa->field_width) / 2;
	}
	else if (diraction == 2)
	{
		pa->field_width = (pa->win_x / 100) * 80;
		pa->h_indent = pa->field_width / 2;
		pa->between = pa->field_width / val->max_x;
		pa->field_height = pa->between * val->max_y;
		pa->u_indent = (pa->win_y - pa->field_height) / 2;
	}
}

void		size_designation(t_paint *pa, t_val *val)
{
	int		max;
	int		direction; /* 1 = upright, 2 = horizontally */

	max = MAX(val->max_x, val->max_y);
	direction = DD(max, val->max_x);
	find_indentation(pa, val, direction);
}
