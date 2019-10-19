/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_er.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:05:57 by emeha             #+#    #+#             */
/*   Updated: 2019/10/20 00:05:58 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_atoi_er(const char *str, int *er)
{
	int			i;
	int			neg;
	int			res;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\f' ||
			str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * 10 / 10 != res)
			return ((neg == -1) ? (*er)++ : (*er)++);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * neg);
}
