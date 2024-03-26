/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:53:59 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:23:26 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	messages_error_av(void)
{
	ft_printf("😰 \033[1;34mles parametre autoriser sont :\033[0m\n\n");
	ft_printf("\033[1;35mmandelbrot\n");
	ft_printf("julia\033[0m\033[1;36m <real>\033[0m\033[1;31m <imaginaire>\033[0m\n");
}

int	main(int ac, char *av[])
{
	t_mlx_data	data;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		data.name = av[1];
		if (ac == 4)
		{
			data.julia_reel = ft_atof(av[2]);
			data.julia_complex = ft_atof(av[3]);
		}
		data_init(&data, data.name);
		fractol_init(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
	{
		messages_error_av();
		exit(EXIT_FAILURE);
	}
	return (0);
}
