/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:19:23 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/17 22:41:23 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_puthaxell(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16 || nbr == 0)
		count += ft_puthaxell(nbr / 16);
	count += write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}

int	ft_print_ptr(void	*ptr)
{
	int				count;
	unsigned long	adrss;

	count = 0;
	adrss = (unsigned long)ptr;
	if (adrss == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_puthaxell(adrss);
	}
	return (count);
}
