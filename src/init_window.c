/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 04:10:47 by emeha             #+#    #+#             */
/*   Updated: 2019/10/20 04:56:43 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	deal_key(int key)
{
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int init_window()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xff0505);
	mlx_key_hook(win_ptr, deal_key, (void*)0);
	mlx_loop(mlx_ptr);
	return (0);
}
