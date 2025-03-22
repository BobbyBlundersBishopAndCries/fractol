/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:19:00 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/22 17:05:04 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	param_initializing_mandelbrot(t_fractal *f)
{
	f->min.re = -2.0;
	f->max.re = 1.0;
	f->min.im = -1.5;
	f->max.im = 1.5;
	f->r = 10;
	f->g = 10;
	f->b = 10;
	f->fractol_type = 1;
	f->name = "Mandelbrot";
}

static int	calculate_iterations_mandelbrot(t_complex point)
{
	t_complex	z_n;
	double		z_npone_r;
	double		z_npone_i;
	int			iter;

	iter = 0;
	z_n.im = 0;
	z_n.re = 0;
	while (iter < MAX_ITER)
	{
		z_npone_r = z_n.re;
		z_npone_i = z_n.im;
		z_n.re = z_npone_r * z_npone_r - z_npone_i * z_npone_i + point.re;
		z_n.im = 2 * z_npone_r * z_npone_i + point.im;
		if (z_n.re * z_n.re + z_n.im * z_n.im > 4)
			break ;
		iter++;
	}
	return (iter);
}

void	create_mandelbrot(t_fractal *f)
{
	int			re;
	int			im;
	t_complex	point;
	char		*address;

	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	im = 0;
	while (im++ < HEIGHT)
	{
		re = 0;
		while (re++ < WIDTH)
		{
			point.re = f->min.re + (f->max.re - f->min.re) * re / (WIDTH - 1);
			point.im = f->min.im + (f->max.im - f->min.im) * im / (HEIGHT - 1);
			f->curr = calculate_iterations_mandelbrot(point);
			if (f->curr == MAX_ITER)
				f->color = create_trgb(1, f->r, f->g, f->b);
			else
				f->color = create_trgb(1, f->r, f->g, f->b) * f->curr;
			address = f->addr + im * f->line_len + re * (f->bpp / 8);
			*(unsigned int *)address = f->color;
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
