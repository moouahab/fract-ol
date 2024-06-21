/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:53:11 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:57:33 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../printf/include/ft_printf.h"
# include "../libft/libft.h"
# include "complexe.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 10
# define SCALE_FACTOR 4

# define BLACK   0x000000
# define RED     0xFF0000
# define GREEN   0x00FF00
# define YELLOW  0xFFFF00
# define BLUE    0x0000FF
# define MAGENTA 0xFF00FF
# define CYAN    0x00FFFF
# define WHITE   0xFFFFFF

typedef enum s_bool
{
	false,
	true
}t_bool;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		*name;
	int			width;
	int			height;
	int			iteration;
	double		escape_value;
	double		shift_x;
	double		shift_y;
	double		julia_reel;
	double		julia_complex;
	double		zoom_p;
	t_complexe	z;
	t_img		img;
}t_mlx_data;

double	ft_atof(char *str);
void	farctolcmp(t_complexe	*z, t_complexe	*c, t_mlx_data	*data);
int		convergence(t_mlx_data *data, double x, double y);
void	render_background(t_mlx_data *data, t_img *img, int color);
void	fractol_init(t_mlx_data *data);
void	fractol_render(t_mlx_data	*data);
void	init_color(int *color_1, int *color_2, int *color_3, int *color_4);
void	ma_arc(t_mlx_data *data, int x, int y);
int		draw_mandelbrot(t_mlx_data	*mlx);
int		color_cyber(int x, int y);
int		key_press(int keysym, t_mlx_data *data);
void	bg_arc(t_mlx_data *data, t_img	*img);
int		mouse_event(int button, int x, int y, t_mlx_data	*data);
int		color_pixel(t_mlx_data	*data, int x, int y, int seuil);
int		window_close(t_mlx_data	*data);
int		free_window(int keysym, t_mlx_data *data);
int		render(t_mlx_data	*data);
void	img_pix_put(t_img	*img, int x, int y, int color);
void	data_init(t_mlx_data	*mlx, char	*str);

#endif
