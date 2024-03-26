/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:46:19 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:50:47 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEXE_H
# define COMPLEXE_H

# include <math.h>

typedef struct s_map_complexe
{
	double	new_max;
	double	new_min;
	double	old_max;
	double	old_min;
}t_map_complexe;

typedef struct s_complexe
{
	double	reel;
	double	complexe;
	double	argc;
	double	modulo;
}t_complexe;

t_complexe	complexe_init(double reel, double complexe);
double		map_complexe(double unscled, t_map_complexe	*map);

// complexe form a + bi
t_complexe	sqrt_complexe(t_complexe	z);
t_complexe	operation(t_complexe	*z1, t_complexe	*z2, char c);
void		module_and_argument(t_complexe	*z);
t_complexe	conjugai_complexe(t_complexe	z);
t_complexe	mul_complexe(t_complexe	z1, t_complexe	z2);
t_complexe	div_complexe(t_complexe	z1, t_complexe	z2);
t_complexe	puissance_complexe(t_complexe	z, int exposant);

t_complexe	racine_carre_complexe(t_complexe	z);

#endif
