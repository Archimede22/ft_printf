# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucapik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 14:23:08 by jucapik           #+#    #+#              #
#    Updated: 2019/01/31 19:29:57 by naali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_memalloc.c ft_bzero.c ft_memmove.c ft_memcpy.c \
	   ft_memccpy.c ft_memset.c ft_memchr.c ft_memchr.c \
	   ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	   ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	   ft_strnstr.c ft_strnew.c ft_strmap.c ft_strmapi.c \
	   ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	   ft_itoa.c ft_strlcat.c ft_strlen.c ft_isalpha.c \
	   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_strcmp.c ft_strncmp.c \
	   ft_memcmp.c ft_atoi.c ft_strequ.c ft_strnequ.c \
	   ft_memdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	   ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_strdel.c ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   ft_strlen_s.c ft_strcpy_s.c ft_memccpy_s.c ft_memset_s.c \
	   ft_lstaddend.c ft_strndup.c ft_abs.c ft_strinsert.c	\
		ft_swap.c

BNRY = ft_memalloc.o ft_bzero.o ft_memmove.o ft_memcpy.o \
	   ft_memccpy.o ft_memset.o ft_memchr.o ft_memchr.o \
	   ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
	   ft_strncat.o ft_strchr.o ft_strrchr.o ft_strstr.o \
	   ft_strnstr.o ft_strnew.o ft_strmap.o ft_strmapi.o \
	   ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
	   ft_itoa.o ft_strlcat.o ft_strlen.o ft_isalpha.o \
	   ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	   ft_toupper.o ft_tolower.o ft_strcmp.o ft_strncmp.o \
	   ft_memcmp.o ft_atoi.o ft_strequ.o ft_strnequ.o \
	   ft_memdel.o ft_strclr.o ft_striter.o ft_striteri.o \
	   ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
	   ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
	   ft_putnbr_fd.o ft_strdel.o ft_lstnew.o ft_lstdelone.o \
	   ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
	   ft_strlen_s.o ft_strcpy_s.o ft_memccpy_s.o ft_memset_s.o \
	   ft_lstaddend.o ft_strndup.o ft_abs.o ft_strinsert.o \
		ft_swap.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(BNRY)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(BNRY)

fclean : clean
	/bin/rm -rf libft.h.gch
	/bin/rm -rf $(NAME)

re: fclean all
