/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:06:47 by emeha             #+#    #+#             */
/*   Updated: 2019/10/22 03:06:50 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int 	check_color(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

void	pars_color(t_point *po, char *s)
{
	char **split;

	split = ft_strsplit(s, ',');
	po->color = ft_atoi_base(split[1], 16);
	free(split[1]);
	free(split[0]);
	free(split);
}
