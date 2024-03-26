/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:54:56 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 17:23:48 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../include/fractol.h"
#include "../include/complexe.h"

void	event_hook(t_mlx_data	*data)
{
	mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, mouse_event, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->mlx_win, DestroyNotify,
		StructureNotifyMask, window_close, data);
}

void	error_msg(void)
{
	perror("\033[1;31mError mlx non init\033[0m");
	exit(EXIT_FAILURE);
}

void	data_init(t_mlx_data	*mlx, char	*str)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error_msg();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, str);
	if (!mlx->mlx_win)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		error_msg();
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		error_msg();
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.line_length, &mlx->img.endian);
	event_hook(mlx);
}

int	render(t_mlx_data	*data)
{
	data->height = HEIGHT;
	data->width = WIDTH;
	if (!data->mlx_win)
		return (1);
	draw_mandelbrot(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	return (0);
}
