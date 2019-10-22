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

int 		valid_color(char *line, int *i)
{
	int	size;

	size = 9;
	while (line[*i] != '\0' && size != 0)
	{
		if (size == 9)
		{
			if (line[*i] != ',')
				return (1);
		}
		else if (size == 8)
		{
			if (line[*i] != '0')
				return (1);
		}
		else if (size == 7)
		{
			if (line[*i] != 'x')
				return (1);
		}
		else if (size < 7 && size > -1)
		{
			if (!((line[*i] >= 'A' && line[*i] <= 'F') ||
					(line[*i] >= 'a' && line[*i] <= 'f') ||
					(line[*i] >= '0' && line[*i] <= '9')))
				return (1);
		}
		else
			return (1);
		size--;
		(*i)++;
	}
	return (0);
}

void		check_alph_line(char *line, t_val *val)
{
	int		i;
	int		point;
	int 	ch;

	ch = 0;
	i = 0;
	point = 0;
	if (line[i] == ',')
		error("comma at the beginning of a line");
	while (line[i] != '\0')
	{
		if (line[i] == ',' && line[i - 1] != ' ')
		{
			if (valid_color(line, &i))
				error("not formatting color correctly");
			if (!(line[i] == ' ' || line[i] == '\0'))
				error("after color there should be space");
			continue ;
		}
		if ((line[i] >= '0' && line[i] <= '9') ||
			(line[i] == ' '))
		{
			if (ch == 0 &&
				(line[i] >= '0' && line[i] <= '9'))
				point++;
			if (line[i] == ' ')
				ch = 0;
			else
				ch = 1;
			i++;
		}
		else
			error("invalid characters or double space");
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
		if (check_color(split[i]))
			pars_color(po_tmp, split[i]);
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
//		ft_putstr(line);
//		ft_putchar('\n');
		check_line(line, *val);
		free(line);
	}
	(*val)->max_x--;
	if (po->x == -1)
		error("no data on map");
	return (map_creation(po, *val));
}
