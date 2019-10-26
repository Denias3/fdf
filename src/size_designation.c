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

void	make_accurate(t_paint *pa, t_val *val)
{
	pa->field_width = pa->between * val->max_x;
	pa->field_height = pa->between * val->max_y;
	pa->h_indent = (pa->win_x - pa->field_width) / 2;
	pa->u_indent = (pa->win_y - pa->field_height) / 2;
}

static void	find_indentation(t_paint *pa, t_val *val, int diraction, int percent)
{
	if (diraction == 1)
	{
		pa->field_height = (pa->win_y / 100) * percent;
		pa->u_indent = (pa->win_y - pa->field_height) / 2;
		pa->between = pa->field_height / val->max_y;
		if ((pa->between * val->max_x) > pa->win_x)
		{
			find_indentation(pa, val, 2, percent);
			return ;
		}
		pa->field_width = pa->between * val->max_x;
		pa->h_indent = (pa->win_x - pa->field_width) / 2;
		return ;
	}
	pa->field_width = (pa->win_x / 100) * percent;
	pa->h_indent = (pa->win_x - pa->field_width) / 2;
	pa->between = pa->field_width / val->max_x;
	if ((pa->between * val->max_y) > pa->win_y)
	{
		find_indentation(pa, val, 1, percent);
		return ;
	}
	pa->field_height = pa->between * val->max_y;
	pa->u_indent = (pa->win_y - pa->field_height) / 2;
}

void		size_designation(t_paint *pa, t_val *val, int percent)
{
	double	max;
	int		direction; /* 1 = upright, 2 = horizontally */

	max = MAX(val->max_x, val->max_y);
	direction = DD(max, val->max_x);
	find_indentation(pa, val, direction, percent);
	if (pa->between == 0)
		pa->between = 1;
	pa->between_st = pa->between;
	make_accurate(pa, val);
	printf("pa->between - %d\n", pa->between);
}
