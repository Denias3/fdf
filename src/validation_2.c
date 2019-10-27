/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:26:30 by emeha             #+#    #+#             */
/*   Updated: 2019/10/27 20:26:32 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		valid_color_2(char *line, int *i, int *size)
{
	if ((*size) == 9)
	{
		if (line[*i] != ',')
			return (1);
	}
	else if ((*size) == 8)
	{
		if (line[*i] != '0')
			return (1);
	}
	else if ((*size) == 7)
	{
		if (line[*i] != 'x')
			return (1);
	}
	else if ((*size) < 7 && (*size) > -1)
	{
		if (!((line[*i] >= 'A' && line[*i] <= 'F') ||
			(line[*i] >= 'a' && line[*i] <= 'f') ||
			(line[*i] >= '0' && line[*i] <= '9')))
			return (1);
	}
	else
		return (1);
	return (0);
}

void	check_alph_line_2(char *line, int *i, int *point, int *ch)
{
	if ((line[*i] >= '0' && line[*i] <= '9') ||
		(line[*i] == ' ') ||
			(line[*i] == '-'))
	{
		if ((*ch) == 0 &&
				((line[*i] >= '0' && line[*i] <= '9') ||
			(line[*i] == '-')))
			(*point)++;
		if (line[*i] == ' ')
			(*ch) = 0;
		else
			(*ch) = 1;
		(*i)++;
	}
	else
		error("invalid characters or double space");
}
