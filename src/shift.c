/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 06:47:21 by emeha             #+#    #+#             */
/*   Updated: 2019/10/22 06:47:23 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	shift_map(t_point *po, int sh, int bet)
{
	while (po != NULL)
	{
		if (sh == 1)
			po->y -= (bet / 10);
		else if (sh == 2)
			po->x += (bet / 10);
		else if (sh == 3)
			po->y += (bet / 10);
		else if (sh == 4)
			po->x -= (bet / 10);
		po = po->next;
	}
}

void	twist_map_x(t_point *po, int sh)
{
	while (po != NULL)
	{
		if (sh == 0)
		{
			po->x = po->x * cos(0.1) + po->y * sin(0.1);
			po->y = po->x * sin(0.1) + po->y * cos(0.1);
		}
		else if (sh == 1)
		{
			po->x = po->x * cos(-0.1) + po->y * sin(-0.1);
			po->y = po->x * sin(-0.1) + po->y * cos(-0.1);
		}
		po = po->next;
	}
}
