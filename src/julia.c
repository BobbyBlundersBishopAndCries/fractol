/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:15:39 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/22 15:58:13 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	param_initializing_julia(t_fractal *f, char *v1, char *v2)
{
	f->julia.re = ft_atod(v1);
	f->julia.im = ft_atod(v2);
	f->min.re = -2.0;
	f->max.re = 2.0;
	f->min.im = -1.5;
	f->max.im = 1.5;
	f->r = 50;
	f->g = 50;
	f->b = 50;
	f->fractol_type = 2;
	f->name = "Julia";
	if (!(f->julia.re >= -2.0 && f->julia.re <= 2.0) || !(f->julia.im >= -2.0
			&& f->julia.im <= 2.0))
		instruction();
}

static int	calculate_iterations_julia(t_complex *point, double cr, double ci)
{
	double		x;
	double		y;
	t_complex	new_point;
	int			iteration;

	iteration = 0;
	x = point->re;
	y = point->im;
	while (iteration < MAX_ITER)
	{
		new_point.re = x * x - y * y + cr;
		new_point.im = 2 * x * y - ci;
		x = new_point.re;
		y = new_point.im;
		if (x * x + y * y > 4)
			return (iteration);
		iteration++;
	}
	return (MAX_ITER);
}

void	create_julia(t_fractal *f)
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
			f->curr = calculate_iterations_julia(&point, f->julia.re,
					f->julia.im);
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
