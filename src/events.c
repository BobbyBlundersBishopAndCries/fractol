/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:05:37 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/24 23:06:06 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	exit_with_error(const char *msg)
{
	ft_printf(1, "Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

static void	zoom_out(t_fractal *f, double re, double im)
{
	f->max.re = (f->max.re - re) / ZOOM_FACTOR + re;
	f->min.re = (f->min.re - re) / ZOOM_FACTOR + re;
	f->min.im = (f->min.im - im) / ZOOM_FACTOR + im;
	f->max.im = (f->max.im - im) / ZOOM_FACTOR + im;
}

static void	zoom_in(t_fractal *f, double re, double im)
{
	f->max.re = (f->max.re - re) * ZOOM_FACTOR + re;
	f->min.re = (f->min.re - re) * ZOOM_FACTOR + re;
	f->min.im = (f->min.im - im) * ZOOM_FACTOR + im;
	f->max.im = (f->max.im - im) * ZOOM_FACTOR + im;
}

int	zoom(int key, int x, int y, t_fractal *f)
{
	t_complex	center;

	center.re = (f->min.re) + (f->max.re - f->min.re) * x / (WIDTH - 1.0);
	center.im = (f->min.im) + (f->max.im - f->min.im) * y / (HEIGHT - 1.0);
	if (key == MOUSE_UP)
		zoom_in(f, center.re, center.im);
	if (key == MOUSE_DOWN)
		zoom_out(f, center.re, center.im);
	precise_fractol(f);
	return (0);
}
