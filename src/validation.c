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
	if (val->max_x == -1)
		val->max_x = point;
	else if (val->max_x != point)
		error("lines have different sizes");
}

void	pars_point(char *line, t_point *po, t_val *val)
{
	char	**split;
	t_point	*po_tmp;
	int 	i;

	i = 0;
	po_tmp = val->end_point;
	split = ft_strsplit(line, ' ');
	while (po_tmp->next != NULL)
		po_tmp = po_tmp->next;
	while (split[i] != NULL)
	{
		po_tmp->next = create_point();
		po_tmp->y =
		i++;
	}

}

void	check_line(char *line, t_point *po, t_val *val)
{
	check_alph_line(line, val);
	pars_point(line, po, val);
}

t_point	***validation()
{
	int		fd;
	char	*line;
	t_val	*val;
	t_point *po;

	po = create_point();
	val = create_val(po);
	fd = open("/Users/emeha/CLionProjects/fdf/maps/42.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		check_line(line, po, val);
	}
	return (0);
}
