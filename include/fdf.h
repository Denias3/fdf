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
# include "../minilibx/mlx.h"

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}					t_point;

typedef	struct		s_val
{
	int				max_x;
	int 			max_y;
	t_point			*start_point;
	t_point			*end_point;
}					t_val;

typedef	struct		s_paint
{
	int 			win_x;
	int 			win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	int				h_indent;
	int				u_indent;
	int				field_width;
	int				field_height;
	int				between;
}					t_paint;


void		print_line(t_paint *paint, int x1, int x2, int y1, int y2);



t_point				***validation(char *name_map, t_val	**val);
void				error(char *er);
t_point				*create_point(void);
t_val				*create_val(t_point *po);
int					ft_atoi_er(const char *str, int *er);
void				free_split(char **split);
t_point				***map_creation(t_point *po, t_val *val);
void                map_val_free(t_point ***map, t_val *val);
int					init_window(t_point	***map, t_val *val);
t_paint				*create_paint();
void				drawLine(t_point *one, t_point *two, t_paint *paint);
void				size_designation(t_paint *pa, t_val *val);
void				starting_position(t_point *po, t_paint *paint);
int					ft_abs(int num);

#endif
