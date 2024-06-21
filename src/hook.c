/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:12:19 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:33:13 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * Attention hook peut cible un seule vent dont cree des fonction event
 * gobale est naissaire merci 
 * 
 * int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
 * int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
 * int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
 * int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
 * 
 * int	mlx_hook(void *win_ptr, int x_event, int x_mask, int 
 * (*funct)(), void *param)
 * 
 * win_ptr est le pointeur vers une fenêtre.
 * 
 * func_ptr est un pointeur vers une fonction qui retourne un int et qui prend 
 * des paramètres non définis. 
 * 
 * Attention, ce n’est pas la même chose que : le dernier signifie NO argument 
 * tandis que le premier signifie 
 * « n’importe quel ensemble d’arguments ».(*func_ptr)()(*func_ptr)(void)
*/

/**
 * function echape(t_mlx_data   *data)
 * ou 
 * function window()
 * 
 * cette fonction vas libere la memmoir chaque foit qu'on appuie sur echape  
*/

int	free_window(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape || keysym == XK_c)
		window_close(data);
	return (EXIT_FAILURE);
}

int	window_close(t_mlx_data	*data)
{
	ft_printf("\033[1;34mGOODBYE MAN 😉\033[0m\n");
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
	return (true);
}

int	mouve_mandelbort(int keysym, t_mlx_data	*data)
{
	if (keysym == XK_Left)
		data->shift_x += (0.5 * data->zoom_p);
	else if (keysym == XK_Right)
		data->shift_x -= (0.5 * data->zoom_p);
	else if (keysym == XK_Up)
		data->shift_y -= (0.5 * data->zoom_p);
	else if (keysym == XK_Down)
		data->shift_y += (0.5 * data->zoom_p);
	else if (keysym == XK_p)
		data->iteration += 10;
	else if (keysym == XK_minus)
		data->iteration -= 10;
	return (0);
}

int	key_press(int keysym, t_mlx_data *data)
{
	free_window(keysym, data);
	if (keysym == XK_Left
		|| keysym == XK_Right
		|| keysym == XK_Up
		|| keysym == XK_Down
		|| keysym == XK_p
		|| keysym == XK_minus)
	{
		mouve_mandelbort(keysym, data);
		render(data);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_mlx_data	*data)
{
	(void)x;
	(void)y;
	if (button == Button4)
			data->zoom_p *= 1.05;
	else if (button == Button5)
		data->zoom_p /= 1.05;
	render(data);
	return (0);
}
