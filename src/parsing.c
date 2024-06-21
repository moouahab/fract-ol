/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:44:11 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:25:29 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_atof(char *str)
{
	long	part_int;
	double	part_farct;
	double	div;

	div = 1;
	part_farct = 0.0;
	part_int = ft_atol(str);
	while (*str != '.' && *str)
		str++;
	if (*str == '.')
		str++;
	while (*str)
	{
		div = div / 10;
		part_farct = part_farct + (*str++ - '0') * div;
	}
	return (part_int + part_farct);
}
