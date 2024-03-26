# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:44:09 by moouahab          #+#    #+#              #
#    Updated: 2023/12/01 13:03:39 by moouahab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC = 	src/ft_printf.c  fonction/ft_printstr.c fonction/ft_printchar.c fonction/ft_putnbr_unsigned.c\
		fonction/ft_printnbr.c fonction/ft_putnbr_base.c fonction/ft_print_ptr.c \

SRCS = ${LIBC}

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@ar -rsc ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		@rm -f ${OBJS}

fclean:	clean;
		@rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
