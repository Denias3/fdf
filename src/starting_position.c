/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:40:31 by emeha             #+#    #+#             */
/*   Updated: 2019/10/21 22:40:37 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	starting_position(t_point *po, t_paint *paint)
{
	while (po != NULL)
	{
		po->x = paint->between * po->x;
		po->y = paint->between * po->y;
		po->z = paint->between * po->z;
		po->x += paint->h_indent;
		po->y += paint->u_indent;
		po = po->next;
	}
}
