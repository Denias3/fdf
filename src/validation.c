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

int check_alph_line(char *line)
{
	int i;

	i = 0;
	if (line[i] == ' ')
		return (1);
	while(line[i] != '\0')
	{
		if (line[i + 1] == '\0' && line[i] == ' ')
			return (1);
		if ((line[i] >= '0' && line[i] <= '9') ||
			(line[i] == ' ' && line[i - 1] != ' '))
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_line(char *line, t_point *po)
{
	if (check_alph_line(line))
		return (1);

	return (0);
}

int validation(t_point *po)
{
	int		fd;
	char	*line;

	po = NULL;
	fd = open("/Users/emeha/CLionProjects/fdf/maps/42.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (check_line(line, po))
			error("not valid line in the map");
	}
	return (0);
}
