/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:06:04 by mohabid           #+#    #+#             */
/*   Updated: 2025/03/22 17:00:21 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# define WIDTH 700
# define HEIGHT 700
# define MAX_ITER 200
# define ESC 65307
# define ON_DESTROY 17
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractal
{
	/* title */
	char		*name;
	/* address of pixel writing */
	char		*addr;
	int			endian;
	int			bpp;
	int			line_len;
	/* the limits of the fractal */
	t_complex	min;
	t_complex	max;
	/* mlx_ptr for server connection establishement
	   win_ptr pointer to the window for window creation
	   img_ptr pointer to the image for image creation
	*/
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	/* colors */
	double		r;
	double		g;
	double		b;
	int			color;
	/* for rendering choice */
	int			fractol_type;
	/* for current iteration */
	int			curr;
	/* julia values */
	t_complex	julia;
}				t_fractal;
/*   utils.c   */
void	instruction(void);
int		create_trgb(int t, int r, int g, int b);
void	open_window(t_fractal *f);
void	close_window(t_fractal *f);
void	precise_fractol(t_fractal *f);
/*   mandelbrot.c   */
void	param_initializing_mandelbrot(t_fractal *param);
void	create_mandelbrot(t_fractal *f);
/*   ft_atod.c   */
double	ft_atod(const char *str);
/*   julia.c     */
void	param_initializing_julia(t_fractal *f, char *v1, char *v2);
void	create_julia(t_fractal *f);
/*   events.c   */
int		zoom(int key, int x, int y, t_fractal *f);
#endif