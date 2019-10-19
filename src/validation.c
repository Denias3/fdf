/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:32:23 by emeha             #+#    #+#             */
/*   Updated: 2019/10/19 20:32:25 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>

void	check_alph_line(char *line, t_val *val)
{
	int i;
	int point;

	i = 0;
	point = 0;
	if (line[i] == ' ')
		error("space at the beginning of the line");
	while(line[i] != '\0')
	{
		if (line[i + 1] == '\0' && line[i] == ' ')
			error("space at the end of the line");
		if ((line[i] >= '0' && line[i] <= '9') ||
			(line[i] == ' ' && line[i - 1] != ' '))
		{
			if (line[i] == ' ')
				point++;
			i++;
		}
		else
			error("invalid characters");
	}
	if (val->max_point == -1)
		val->max_point = point;
	else if (val->max_point != point)
		error("lines have different sizes");
}

void	pars_point(char *line, t_point *po)
{

}

void	check_line(char *line, t_point *po, t_val *val)
{
	check_alph_line(line, val);
	pars_point(line, po);
}

t_point	***validation()
{
	int		fd;
	char	*line;
	t_val	*val;
	t_point *po;

	po = create_point();
	val = create_val();
	fd = open("/Users/emeha/CLionProjects/fdf/maps/42.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		check_line(line, po, val);
	}
	return (0);
}
