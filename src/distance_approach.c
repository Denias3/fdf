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

void	distance(t_paint *paint)
{
	paint->between = paint->between - 1;
}

void	approach(t_paint *paint)
{
	paint->between += 1;
}