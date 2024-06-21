/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:31:19 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/17 22:41:23 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_check_sign(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (0);
		str++;
	}
	return (1);
}

static int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int			count;
	int			base_len;
	long int	long_nbr;

	long_nbr = nbr;
	count = 0;
	base_len = ft_strlen(base);
	if (base_len <= 1
		|| (ft_check_sign(base) == 0)
		|| (ft_check_base(base) == 0))
		return (0);
	if (long_nbr < 0)
	{
		long_nbr = -long_nbr;
		count += write(1, "-", 1);
	}
	if (long_nbr > base_len -1)
		count += ft_putnbr_base(long_nbr / base_len, base);
	count += ft_printchar_fd(base[long_nbr % base_len], 1);
	return (count);
}
