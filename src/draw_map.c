/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 00:42:40 by emeha             #+#    #+#             */
/*   Updated: 2019/10/22 00:42:41 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//void	draw_map(t_point ***map, t_paint *paint)
//{
//	int 	x;
//	int 	y;
//
//	y = 0;
//	while (map[y] != NULL)
//	{
//		x = 0;
//		while (map[y][x] != NULL)
//		{
//			paint->shift_x++;
//			paint->shift_x--;
//			if (map[y][x + 1] && map[y][x])
//				draw_line(map[y][x],map[y][x + 1], paint);
//			if (map[y + 1] && map[y + 1][x] && map[y][x])
//				draw_line(map[y][x], map[y + 1][x], paint);
//			x++;
//		}
//		y++;
//	}
//}
