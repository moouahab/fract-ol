/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 03:01:53 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:48:45 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * [CONVEGERCE]
 * 
 * En mathématiques, une série est dite convergente si la suite 
 * de ses sommes partielles a une limite dans l'espace considéré. 
 * Dans le cas contraire, elle est dite divergente.
 * 
 * 
*/

void	fractol_init(t_mlx_data *data)
{
	data->escape_value = 4;
	data->iteration = 400;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->zoom_p = 1.0;
}

void	farctolcmp(t_complexe	*z, t_complexe	*c, t_mlx_data	*data)
{
	if (!ft_strncmp(data->name, "julia", 5))
	{
		c->reel = data->julia_reel;
		c->complexe = data->julia_complex;
	}
	else
	{
		c->reel = z->reel;
		c->complexe = z->complexe;
	}
}

int	convergence(t_mlx_data	*data, double x, double y)
{
	int			i;
	t_complexe	z;
	t_complexe	c;
	t_complexe	sqrt_c;

	z = complexe_init((map_complexe(x,
					&(t_map_complexe){-2, 2, 0, WIDTH}) * data->zoom_p)
			+ data->shift_x,
			(map_complexe(y,
					&(t_map_complexe){2, -2, 0, HEIGHT}) * data->zoom_p)
			+ data->shift_y);
	farctolcmp(&z, &c, data);
	i = 0;
	while (i < data->iteration)
	{
		sqrt_c = sqrt_complexe(z);
		z = operation(&sqrt_c, &c, '+');
		if ((z.reel * z.reel) + (z.complexe * z.complexe) > data->escape_value)
			return (i);
		i++;
	}
	return (i);
}

int	draw_mandelbrot(t_mlx_data	*mlx)
{
	int	x;
	int	y;
	int	converge;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			converge = convergence(mlx, x, y);
			color = color_cyber(converge, converge);
			img_pix_put(&mlx->img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}
