/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:25:54 by fschille          #+#    #+#             */
/*   Updated: 2019/10/19 23:25:56 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		free_points(t_point *po)
{
	t_point *tmp;

	while (po != NULL)
	{
		tmp = po;
		po = po->next;
		free(tmp);
	}
}

void		map_val_free(t_point ***map, t_paint *paint)
{
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != NULL)
		{
			free(map[y][x]);
			x++;
		}
		free(map[y]);
		y++;
	}
	free(map);
	free_points(paint->val->init_point);
	free(paint->val);
	free(paint->mid);
	free(paint);
}

t_point		***map_creation(t_point *po, t_val *val)
{
	t_point	***map;
	int		x;
	int		y;

	y = 0;
	map = (t_point***)malloc(sizeof(t_point**) * (val->max_y + 2));
	while (po != NULL)
	{
		x = 0;
		map[y] = (t_point**)malloc(sizeof(t_point*) * (val->max_x + 2));
		while (po != NULL && y == po->y)
		{
			map[y][x] = po;
			po = po->next;
			x++;
		}
		map[y][x] = NULL;
		y++;
	}
	map[y] = NULL;
	return (map);
}
