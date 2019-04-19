#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucapik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 14:01:47 by jucapik           #+#    #+#              #
#    Updated: 2019/02/06 18:26:29 by jucapik          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a

TSTNAME		=	test

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror

SRC0		=	ctof.c	ft_printf.c param.c	get_param.c \
				print.c	c_param.c id_param.c get_size.c get_type_int.c \
				put_nbr_base.c print_prec.c print_nb_char.c oxx_param.c \
				print_prec_unsigned.c u_param.c p_param.c f_param.c \
				print_coma.c s_param.c print_double_entier.c prct_param.c \
				f_param_helper.c

SRCLIB		=	libft/ft_atoi.c libft/ft_memdel.c libft/ft_strlen.c \
				libft/ft_putchar.c libft/ft_strndup.c libft/ft_putnbr.c \
				libft/ft_putstr.c libft/ft_strdup.c libft/ft_swap.c

SRCPATH0	=	.

SOURCES0	=	$(addprefix $(SRCPATH0)/, $(SRC0))

HDR0		=	ft_printf.h opts.h

HDRPATH0	=	.

HEADERS0	=	$(addprefix $(HDRPATH0)/, $(HDR0))

LIBNAME		=	ft

LIBPATH		=	./libft

LIBHEAD		=	./libft

SOURCESLIB	=	$(addprefix $(LIBPATH)/, $(SRCLIB))

OBJLIB		=	$(SRCLIB:.c=.o)

OBJ0		=	$(SRC0:.c=.o)

%.o:		$(SRCPATH0)/%.c $(LIBPATH)/%.c
			$(CC) -o $@ -c $^ $(CFLAGS)

.PHONY:		clean fclean re

all:		$(NAME)

test:		$(OBJ0) $(OBJLIB)
			@(cd $(LIBPATH) && $(MAKE))
			$(CC) -c maintest.c -o maintest.o
			$(CC) $(CFLAGS) -o $(TSTNAME) $(OBJ0) $(OBJLIB) maintest.o

cur:		$(OBJ0) $(LIB$(LIBNAME))
			@(cd $(LIBPATH) && $(MAKE))
			ar rc $(NAME) $(OBJ0) $(OBJLIB)
			ranlib $(NAME)
			cp $(NAME) /Users/naali/Downloads/ft_printf_checker/

$(NAME):	$(OBJ0) $(LIB$(LIBNAME))
			@(cd $(LIBPATH) && $(MAKE))
			ar rc $(NAME) $(OBJ0) $(OBJLIB)
			ranlib $(NAME)

clean:
			@(cd $(LIBPATH) && $(MAKE) clean)
			rm -rf maintest.o
			rm -rf $(OBJ0)

fclean:		clean
			rm -rf $(LIBPATH)/lib$(LIBNAME).a
			rm -rf $(NAME)
			rm -rf $(TSTNAME)

re:			fclean all

ret:		fclean test

rec:		fclean cur
