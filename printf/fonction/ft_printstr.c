/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:06:56 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/17 22:41:23 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printstr_fd(char	*str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		i += write(1, "(null)", 6);
	else
	{
		while (str[i])
			ft_printchar_fd(str[i++], fd);
	}
	return (i);
}
