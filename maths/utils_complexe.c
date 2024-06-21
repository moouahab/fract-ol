/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complexe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:58 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:58:22 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/fractol.h"
#include "../include/complexe.h"

void	module_and_argument(t_complexe	*z)
{
	z->modulo = sqrt(z->reel * z->reel + z->complexe * z->complexe);
	z->argc = atan2(z->complexe, z->reel);
}

double	map_complexe(double unscled, t_map_complexe *map)
{
	return ((map->new_max - map->new_min) * (unscled - map->old_min)
		/ (map->old_max - map->old_min) + map->new_min);
}

t_complexe	complexe_init(double reel, double complexe)
{
	t_complexe	z;

	z.reel = reel;
	z.complexe = complexe;
	module_and_argument(&z);
	return (z);
}

t_complexe	racine_carre_complexe(t_complexe	z)
{
	t_complexe	res;

	res.reel = z.modulo * cos(z.argc * 0.5);
	res.complexe = z.modulo * sin(z.argc * 0.5);
	return (res);
}

t_complexe	sqrt_complexe(t_complexe	z)
{
	t_complexe	res;

	res.reel = (z.reel * z.reel) - (z.complexe * z.complexe);
	res.complexe = 2 * z.reel * z.complexe;
	return (res);
}
