/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:02:56 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/22 16:50:58 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_key_press(int key_code, t_fractal *f)
{
	if (key_code == ESC)
		close_window(f);
	return (0);
}

int	handle_window_close(t_fractal *f)
{
	close_window(f);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ft_strcmp(av[1], "Mandelbrot") == 0 && ac == 2)
		param_initializing_mandelbrot(&fractal);
	else if (ft_strcmp(av[1], "Julia") == 0 && ac == 4)
		param_initializing_julia(&fractal, av[2], av[3]);
	else
		instruction();
	open_window(&fractal);
	precise_fractol(&fractal);
	mlx_key_hook(fractal.win_ptr, handle_key_press, &fractal);
	mlx_mouse_hook(fractal.win_ptr, zoom, &fractal);
	mlx_hook(fractal.win_ptr, ON_DESTROY, 0, handle_window_close, &fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
