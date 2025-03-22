/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:05:37 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/22 16:53:44 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	zoom_out(t_fractal *f, double re, double im)
{
	f->max.re = (f->max.re - re) / 0.8 + re;
	f->min.re = (f->min.re - re) / 0.8 + re;
	f->min.im = (f->min.im - im) / 0.8 + im;
	f->max.im = (f->max.im - im) / 0.8 + im;
}

static void	zoom_in(t_fractal *f, double re, double im)
{
	f->max.re = (f->max.re - re) * 0.8 + re;
	f->min.re = (f->min.re - re) * 0.8 + re;
	f->min.im = (f->min.im - im) * 0.8 + im;
	f->max.im = (f->max.im - im) * 0.8 + im;
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
