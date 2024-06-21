/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:20:12 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/12 12:33:02 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printchar_fd(char c, int fd);
int		ft_printnbr_fd(int nb, int fd);
int		ft_putnbr_unsigned_fd(unsigned int nb, int fd);
int		ft_printstr_fd(char	*str, int fd);
int		ft_print_ptr(void	*ptr);
int		ft_putnbr_base(unsigned int nbr, char	*base);

#endif
