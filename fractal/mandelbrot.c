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


static void    *draw_chunk(void *arg)
{
        t_thread        *t;
        int             x;
        int             y;
        int             converge;
        int             color;

        t = (t_thread *)arg;
        y = t->start_y;
        while (y < t->end_y)
        {
                x = 0;
                while (x < WIDTH)
                {
                        converge = convergence(t->mlx, x, y);
                        color = color_cyber(converge, converge);
                        img_pix_put(&t->mlx->img, x, y, color);
                        x++;
                }
                y++;
        }
        return (NULL);
}

int     draw_mandelbrot(t_mlx_data      *mlx)
{
        pthread_t       threads[THREAD_COUNT];
        t_thread        data[THREAD_COUNT];
        int             segment;
        int             i;

        segment = HEIGHT / THREAD_COUNT;
        i = 0;
        while (i < THREAD_COUNT)
        {
                data[i].mlx = mlx;
                data[i].start_y = i * segment;
                data[i].end_y = (i == THREAD_COUNT - 1) ? HEIGHT : (i + 1) * segment;
                pthread_create(&threads[i], NULL, draw_chunk, &data[i]);
                i++;
        }
        i = 0;
        while (i < THREAD_COUNT)
        {
                pthread_join(threads[i], NULL);
                i++;
        }
        return (0);
}
