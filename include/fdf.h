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
#include <stdio.h> /* Удалить (printf();) */
#include <math.h>

typedef	struct		s_point
{
	int				x;
	int 			y;
	int 			z;
	int				color;
	struct s_point	*next;
}					t_point;

typedef	struct		s_val
{
	int 			max_x;
	int 			max_y;
	t_point			*init_point;
	t_point			*start_point;
	t_point			*end_point;
}					t_val;

typedef	struct		s_paint
{
	t_val			*val;
	t_point			***map;
	int 			iso;
	int 			win_x;
	int 			win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	int				h_indent;
	int				u_indent;
	int				field_width;
	int				field_height;
	int				between;
	int				between_st;
	int				*mid;
	int 			shift_x;
	int 			shift_y;
	double 			cos_sin_x;
	double 			cos_sin_y;
	double 			cos_sin_z;
}					t_paint;

void		print_line(t_paint *paint, int x1, int x2, int y1, int y2, int color);


t_point				***validation(char *name_map, t_val	**val);
void				error(char *er);
t_point				*create_point(void);
t_val				*create_val(t_point *po);
int					ft_atoi_er(const char *str, int *er);
void				free_split(char **split);
t_point				***map_creation(t_point *po, t_val *val);
void				map_val_free(t_point ***map, t_paint *paint);
int					init_window(t_point	***map, t_val *val);
t_paint				*create_paint(t_val *val, t_point ***map);
void				draw_line(t_point *one, t_point *two, t_paint *paint);
void				size_designation(t_paint *pa, t_val *val, int percent);
void				starting_position(t_point *po, t_paint *paint);
int					ft_abs(int num);
void				draw_map(t_point ***map, t_paint *paint);
int					check_color(char *s);
void 				pars_color(t_point *po, char *s);
void				isometric(t_point ***map, t_paint *pa);
int  				key_press(int keycode, void *param);
void				make_accurate(t_paint *pa, t_val *val);
void				distance(t_paint *paint);
void				approach(t_paint *paint);
void				shift_map(t_paint *paint, int sh);
//void				twist_map_z(t_paint *pa, t_point *po, t_val *val);
t_point				*copy_points(t_point *po);
void				map_pass(t_point ***map, void f(t_point*, t_paint*), t_paint *pa);
void				search_map_center(t_point ***map, t_paint *pa);
void				plus(t_point *point, t_paint *pa);
void				replace_op(t_point *replace, t_point *new);
void				replace_op_st(t_point *replace, t_point *new, t_paint *paint);
void				isometric_(t_point ***map, t_paint *pa);
void				twist_map_x_y_z(t_paint *paint, t_point *po, t_val *val);
unsigned int		ft_atoi_base(char *str);

#endif
