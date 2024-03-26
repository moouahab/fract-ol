/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:47:48 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/22 11:11:38 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
* @param *format 	: 	pointeur de formatage
* @param ... 		: 	une ellipse indiquant que des arguments 
* 				supplémentaires peuvent être transmis
*
* @return		:	taill de la chaine de formatage
* @detail 		:	recode un printf
*
* [LIB STDARG]
*
* va_list		:	c'est surcture qui va permetre de connaitre 
* 				le type de d'une variable non defini
*
* va_start		:	va pemettre de intialiser la variable va_list
* va_end		:	va libere la variable va_list
*
* va_arg		:	permet d'extraire et de typee le 
*				paramettre suivant (Attention au cas)
* 				va_args(<variable de type va_list>, <type du parametre>);
*
* 
*
* [NOTE DE SUR PRINTF]
*
* si on trouve un caractre '%' on partique un 
* formatage sur le caratecre suivant
*
*
**/

static int	ft_puthax(unsigned int nbr, char c)
{
	int	count;

	count = 0;
	if (c == 'x' || c == 'p')
		count += ft_putnbr_base(nbr, "0123456789abcdef");
	if (c == 'X')
		count += ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (count);
}

static int	ft_formatage(char c, va_list	args)
{
	int	taill;

	taill = 0;
	if (c == 'c')
		taill += ft_printchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		taill += ft_printstr_fd(va_arg(args, char *), 1);
	else if (c == 'd' || c == 'i')
		taill += ft_printnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		taill += ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		taill += ft_puthax(va_arg(args, unsigned int), c);
	else if (c == 'p')
		taill += ft_print_ptr(va_arg(args, void *));
	else if (c == '%')
		taill += ft_printchar_fd('%', 1);
	return (taill);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_formatage(*format, args);
		}
		else
			count += ft_printchar_fd(*format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}
