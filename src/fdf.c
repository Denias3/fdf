/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:21:50 by emeha             #+#    #+#             */
/*   Updated: 2019/10/19 19:21:52 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_point	***map;
	t_val	*val;

	if (argc != 2)
		error("indicate the path to the map");
	map = validation(argv[1], &val);
	init_window(map);
	map_val_free(map, val);
	return (0);
}
