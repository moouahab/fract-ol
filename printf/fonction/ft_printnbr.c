/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:19:56 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/17 22:41:23 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_count_digit(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
		digit += 1;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

int	ft_printnbr_fd(int nb, int fd)
{
	int	len;

	len = ft_count_digit(nb);
	if (nb == -2147483648)
	{
		ft_printstr_fd("-2147483648", fd);
	}
	else if (nb < 0 && nb > -2147483648)
	{
		ft_printchar_fd('-', fd);
		nb *= -1;
		ft_printnbr_fd(nb, fd);
	}
	else if (nb >= 0 && nb <= 9)
		ft_printchar_fd(nb + 48, fd);
	else if (nb > 9)
	{
		ft_printnbr_fd((nb / 10), fd);
		ft_printnbr_fd((nb % 10), fd);
	}
	return (len);
}
