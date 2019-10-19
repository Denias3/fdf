/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:32:10 by emeha             #+#    #+#             */
/*   Updated: 2019/10/19 20:32:14 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "../libft/libft.h"

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}					t_point;

typedef	struct		s_val
{
	int				max_point;
}					t_val;

t_point				***validation();
void				error(char *er);
t_point				*create_point(void);
t_val				*create_val(void);

#endif
