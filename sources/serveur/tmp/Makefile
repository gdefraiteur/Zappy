# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/04 12:26:23 by gdefrait          #+#    #+#              #
#    Updated: 2014/03/04 12:26:26 by gdefrait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAME_MINILIBX = mlx

CC = gcc -g -I libft/ -Wall -O3

DIR_LIBS = /usr/X11/lib/

LDFLAGS = -L /usr/X11/lib -lmlx -lXext -lX11

SRC = main.c img_utils.c affmap.c getmap.c \
libft/ft_atoi.c libft/ft_memmove.c libft/ft_strcpy.c libft/ft_strncpy.c \
libft/ft_bzero.c libft/ft_memset.c libft/ft_strdel.c libft/ft_strnequ.c \
libft/ft_isalnum.c libft/ft_putchar.c libft/ft_strdup.c libft/ft_strnew.c \
libft/ft_isalpha.c libft/ft_putchar_fd.c libft/ft_strequ.c libft/ft_strnstr.c \
libft/ft_isascii.c libft/ft_putendl.c libft/ft_striter.c libft/ft_strrchr.c \
libft/ft_isdigit.c libft/ft_putendl_fd.c libft/ft_striteri.c libft/ft_strsplit.c \
libft/ft_isprint.c libft/ft_putnbr.c libft/ft_strjoin.c libft/ft_strstr.c \
libft/ft_itoa.c libft/ft_putnbr_fd.c libft/ft_strlcat.c libft/ft_strsub.c \
libft/ft_memalloc.c libft/ft_putstr.c libft/ft_strlen.c libft/ft_strtrim.c \
libft/ft_memccpy.c libft/ft_putstr_fd.c libft/ft_strlen_const.c libft/ft_tolower.c \
libft/ft_memchr.c libft/ft_strcat.c libft/ft_strmap.c libft/ft_toupper.c \
libft/ft_memcmp.c libft/ft_strchr.c libft/ft_strmapi.c libft/get_next_line.c \
libft/ft_memcpy.c libft/ft_strclr.c libft/ft_strncat.c \
libft/ft_memdel.c libft/ft_strcmp.c libft/ft_strncmp.c libft/sstrmemdel.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean


