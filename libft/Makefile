#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 14:13:14 by wburgos           #+#    #+#              #
#    Updated: 2015/02/20 14:48:49 by wburgos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CDEBUG = -g3
SRC = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_abs.c ft_sign.c ft_getcolor.c \
		ft_hsvtorgb.c ft_negate.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_isspace.c ft_strnjoin.c \
		ft_strndup.c
OBJ = $(SRC:.c=.o)
INC = includes

%.o: %.c $(INC)/libft.h
	$(CC) $(CFLAGS) -I$(INC) -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "$(NAME) generated"

.PHONY: debug
debug: $(CFLAGS) += $(CDEBUG)
debug: re

.PHONY: every
every: $(CFLAGS) += -Weverything
every: re

.PHONY: clean
clean:
	@/bin/rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: all
all: $(NAME)

.PHONY: re
re: fclean all
