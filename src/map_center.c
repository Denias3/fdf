/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:20:41 by fschille          #+#    #+#             */
/*   Updated: 2019/10/23 23:20:49 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	search_map_center(t_point ***map, t_paint *pa)
{
	int	x;
	int	y;

	x = ((map[pa->val->max_y][pa->val->max_x]->x -
			map[0][0]->x) / 2) + map[0][0]->x;
	y = ((map[pa->val->max_y][pa->val->max_x]->y -
			map[0][0]->y) / 2) + map[0][0]->y;
	pa->mid[0] = (pa->win_x / 2) - x;
	pa->mid[1] = (pa->win_y / 2) - y;
}
