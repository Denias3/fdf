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

void		check_alph_line(char *line, t_val *val)
{
	int		i;
	int		point;

	i = 0;
	point = 0;
	if (line[i] == ' ')
		error("space at the beginning of the line");
	while (line[i] != '\0')
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

void		pars_point(char *line, t_val *val)
{
	char	**split;
	t_point	*po_tmp;
	int		i;
	int		ch;

	i = 0;
	ch = 0;
	po_tmp = val->end_point;
	split = ft_strsplit(line, ' ');
	(val->max_y)++;
	while (split[i] != NULL)
	{
		if (!(val->max_y == 0 && i == 0))
		{
			po_tmp->next = create_point();
			po_tmp = po_tmp->next;
		}
		po_tmp->y = val->max_y;
		po_tmp->x = i;
		po_tmp->z = ft_atoi_er(split[i], &ch);
		if (ch)
			error("too large/small number");
		i++;
	}
	free_split(split);
	val->end_point = po_tmp;
}

void		check_line(char *line, t_val *val)
{
	check_alph_line(line, val);
	pars_point(line, val);
}

t_point		***validation(char *name_map, t_val **val)
{
	int		fd;
	char	*line;
	t_point	*po;

	fd = open(name_map, O_RDONLY);
	po = create_point();
	(*val) = create_val(po);
	if (fd == -1)
		error("file not found");
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		check_line(line, *val);
		free(line);
	}
	if (po->x == -1)
		error("no data on map");
	return (map_creation(po, *val));
}
