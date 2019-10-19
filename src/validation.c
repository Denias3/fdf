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

int		check_alph_line(char *line, t_val *val)
{
	int i;
	int point;

	i = 0;
	point = 0;
	if (line[i] == ' ')
		return (1);
	while(line[i] != '\0')
	{
		if (line[i + 1] == '\0' && line[i] == ' ')
			return (1);
		if ((line[i] >= '0' && line[i] <= '9') ||
			(line[i] == ' ' && line[i - 1] != ' '))
		{
			if (line[i] == ' ')
				point++;
			i++;
		}
		else
			return (1);
	}
	if (val->max_point == -1)
		val->max_point = point;
	else if (val->max_point != point)
		return (1);
	return (0);
}

void	pars_point(char *line, t_point *po)
{

}

int		check_line(char *line, t_point *po, t_val *val)
{
	if (check_alph_line(line, val))
		return (1);
	pars_point(line, po);
	return (0);
}

int		validation(t_point *po)
{
	int		fd;
	char	*line;
	t_val	*val;

	val = create_val();
	po = NULL;
	fd = open("/Users/emeha/CLionProjects/fdf/maps/42.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (check_line(line, po, val))
			error("not valid line in the map");
	}
	return (0);
}
