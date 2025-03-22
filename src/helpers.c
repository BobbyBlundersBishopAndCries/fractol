/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:41:29 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/22 16:57:19 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	instruction(void)
{
	write(2, "Use following commands:\nFor Mandelbrot:\n", 40);
	write(2, "./fractol Mandelbrot\n", 21);
	write(2, "For Julia :\n", 12);
	write(2, "./fractol Julia <value 1> <value 2>\n", 36);
	write(2, " -2.0 <= value 1 <= 2.0 && -1.5 <= value 2 <= 1.5\n", 50);
	exit(EXIT_FAILURE);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	open_window(t_fractal *f)
{
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, HEIGHT, WIDTH, f->name);
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img_ptr,
			&f->bpp, &f->line_len, &f->endian);
}

void	close_window(t_fractal *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	exit(EXIT_SUCCESS);
}

void	precise_fractol(t_fractal *f)
{
	if (f->fractol_type == 1)
		create_mandelbrot(f);
	else if (f->fractol_type == 2)
		create_julia(f);
}
