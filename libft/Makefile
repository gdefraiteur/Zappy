# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garm <garm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/26 23:49:31 by garm              #+#    #+#              #
##   Updated: 2014/06/03 17:26:29 by garm             ###   ########.fr       ##
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a
NAME_BASICS = libft_basics.a
NAME_IO = libft_io.a
NAME_DATA = libft_data.a
NAME_SORTS = libft_sorts.a
NAME_PARSER = libft_parser.a
NAME_UTILS = libft_utils.a
ALLNAME = $(NAME) $(NAME_BASICS) $(NAME_IO) $(NAME_DATA) \
		  $(NAME_SORTS) $(NAME_PARSER) $(NAME_UTILS)

ifeq ($(DEBUG), 1)
	CFLAGS = -g -Wall -Wextra -pedantic
	CC = cc
else
	CFLAGS = -Wall -Werror -Wextra -ansi -pedantic -std=c89
endif

ifeq ($(STRICT), 1)
	CFLAGS += -fstack-protector-all -Wshadow -Wunreachable-code \
			  -Wstack-protector -pedantic-errors -O0 -W -Wundef -fno-common \
			  -Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes \
			  -Wwrite-strings -Wunknown-pragmas -Wdeclaration-after-statement \
			  -Wold-style-definition -Wmissing-field-initializers \
			  -Wpointer-arith -Wnested-externs -Wstrict-overflow=5 -fno-common \
			  -Wno-missing-field-initializers -Wswitch-default -Wswitch-enum \
			  -Wbad-function-cast -Wredundant-decls -fno-omit-frame-pointer \
			  -Wfloat-equal
endif

INCLUDES_DIR = includes
SOURCES_DIR = srcs

DEPENDENCIES = \
			   $(INCLUDES_DIR)/libft.h

DEPENDENCIES_BASICS = \
					  $(INCLUDES_DIR)/libft_basics.h \
					  $(INCLUDES_DIR)/config.h \
					  $(INCLUDES_DIR)/ft_standard_helpers.h \
					  $(INCLUDES_DIR)/ft_number.h \
					  $(INCLUDES_DIR)/ft_char.h \
					  $(INCLUDES_DIR)/ft_string.h \
					  $(INCLUDES_DIR)/ft_memory.h

DEPENDENCIES_IO = \
				  $(INCLUDES_DIR)/libft_io.h \
				  $(INCLUDES_DIR)/ft_output.h \
				  $(INCLUDES_DIR)/ft_input.h

DEPENDENCIES_DATA = \
					$(INCLUDES_DIR)/libft_data.h \
					$(INCLUDES_DIR)/ft_split.h \
					$(INCLUDES_DIR)/ft_list.h \
					$(INCLUDES_DIR)/ft_dlist.h \
					$(INCLUDES_DIR)/ft_btree.h \
					$(INCLUDES_DIR)/ft_htable.h

DEPENDENCIES_SORTS = \
					 $(INCLUDES_DIR)/libft_sorts.h

DEPENDENCIES_PARSER = \
					  $(INCLUDES_DIR)/libft_parser.h

DEPENDENCIES_UTILS = \
					 $(INCLUDES_DIR)/libft_utils.h

DEPENDENCIES_ALL = \
				   $(DEPENDENCIES) \
				   $(DEPENDENCIES_BASICS) \
				   $(DEPENDENCIES_IO) \
				   $(DEPENDENCIES_DATA) \
				   $(DEPENDENCIES_SORTS) \
				   $(DEPENDENCIES_PARSER) \
				   $(DEPENDENCIES_UTILS)

SRCS_BASICS = \
				 $(SOURCES_DIR)/basics/ft_abs.c \
				 $(SOURCES_DIR)/basics/ft_ban_neg.c \
				 $(SOURCES_DIR)/basics/ft_isprint.c \
				 $(SOURCES_DIR)/basics/ft_isascii.c \
				 $(SOURCES_DIR)/basics/ft_isdigit.c \
				 $(SOURCES_DIR)/basics/ft_isalpha.c \
				 $(SOURCES_DIR)/basics/ft_isalnum.c \
				 $(SOURCES_DIR)/basics/ft_isupper.c \
				 $(SOURCES_DIR)/basics/ft_islower.c \
				 $(SOURCES_DIR)/basics/ft_toupper.c \
				 $(SOURCES_DIR)/basics/ft_tolower.c \
				 $(SOURCES_DIR)/basics/ft_iswhitespace.c \
				 $(SOURCES_DIR)/basics/ft_atoi.c \
				 $(SOURCES_DIR)/basics/ft_itoa.c \
				 $(SOURCES_DIR)/basics/ft_strisnum.c \
				 $(SOURCES_DIR)/basics/ft_strlen.c \
				 $(SOURCES_DIR)/basics/ft_strlenc.c \
				 $(SOURCES_DIR)/basics/ft_strdup.c \
				 $(SOURCES_DIR)/basics/ft_strcpy.c \
				 $(SOURCES_DIR)/basics/ft_strncpy.c \
				 $(SOURCES_DIR)/basics/ft_strcat.c \
				 $(SOURCES_DIR)/basics/ft_strncat.c \
				 $(SOURCES_DIR)/basics/ft_strlcat.c \
				 $(SOURCES_DIR)/basics/ft_strchr.c \
				 $(SOURCES_DIR)/basics/ft_strrchr.c \
				 $(SOURCES_DIR)/basics/ft_strstr.c \
				 $(SOURCES_DIR)/basics/ft_strnstr.c \
				 $(SOURCES_DIR)/basics/ft_strcmp.c \
				 $(SOURCES_DIR)/basics/ft_strncmp.c \
				 $(SOURCES_DIR)/basics/ft_strequ.c \
				 $(SOURCES_DIR)/basics/ft_strnequ.c \
				 $(SOURCES_DIR)/basics/ft_strnew.c \
				 $(SOURCES_DIR)/basics/ft_strdel.c \
				 $(SOURCES_DIR)/basics/ft_strclr.c \
				 $(SOURCES_DIR)/basics/ft_striter.c \
				 $(SOURCES_DIR)/basics/ft_striteri.c \
				 $(SOURCES_DIR)/basics/ft_strmap.c \
				 $(SOURCES_DIR)/basics/ft_strmapi.c \
				 $(SOURCES_DIR)/basics/ft_strsub.c \
				 $(SOURCES_DIR)/basics/ft_strjoin.c \
				 $(SOURCES_DIR)/basics/ft_strrev.c \
				 $(SOURCES_DIR)/basics/ft_strtrim.c \
				 $(SOURCES_DIR)/basics/ft_strtrimc.c \
				 $(SOURCES_DIR)/basics/ft_strdelmultic.c \
				 $(SOURCES_DIR)/basics/ft_strcountc.c \
				 $(SOURCES_DIR)/basics/ft_findc.c \
				 $(SOURCES_DIR)/basics/ft_strpickchar.c \
				 $(SOURCES_DIR)/basics/ft_strsubc.c \
				 $(SOURCES_DIR)/basics/ft_memset.c \
				 $(SOURCES_DIR)/basics/ft_bzero.c \
				 $(SOURCES_DIR)/basics/ft_memcpy.c \
				 $(SOURCES_DIR)/basics/ft_memcmp.c \
				 $(SOURCES_DIR)/basics/ft_memchr.c \
				 $(SOURCES_DIR)/basics/ft_memccpy.c \
				 $(SOURCES_DIR)/basics/ft_memmove.c \
				 $(SOURCES_DIR)/basics/ft_memalloc.c \
				 $(SOURCES_DIR)/basics/ft_memdel.c \
				 $(SOURCES_DIR)/basics/ft_smem.c \
				 $(SOURCES_DIR)/basics/ft_smalloc.c \
				 $(SOURCES_DIR)/basics/ft_sfree.c \
				 $(SOURCES_DIR)/basics/ft_sfreeall.c \
				 $(SOURCES_DIR)/basics/ft_remalloc.c

SRCS_IO = \
			 $(SOURCES_DIR)/io/ft_putchar.c \
			 $(SOURCES_DIR)/io/ft_putstr.c \
			 $(SOURCES_DIR)/io/ft_putendl.c \
			 $(SOURCES_DIR)/io/ft_putnbr.c \
			 $(SOURCES_DIR)/io/ft_putnstr.c \
			 $(SOURCES_DIR)/io/ft_putchar_fd.c \
			 $(SOURCES_DIR)/io/ft_putstr_fd.c \
			 $(SOURCES_DIR)/io/ft_putnstr_fd.c \
			 $(SOURCES_DIR)/io/ft_putendl_fd.c \
			 $(SOURCES_DIR)/io/ft_putnbr_fd.c \
			 $(SOURCES_DIR)/io/ft_printf.c \
			 $(SOURCES_DIR)/io/ft_fprintf.c \
			 $(SOURCES_DIR)/io/ft_error.c \
			 $(SOURCES_DIR)/io/ft_fatal.c \
			 $(SOURCES_DIR)/io/get_next_line.c \
			 $(SOURCES_DIR)/io/get_all_lines.c

SRCS_DATA = \
			   $(SOURCES_DIR)/data/ft_strsplit.c \
			   $(SOURCES_DIR)/data/ft_split_create.c \
			   $(SOURCES_DIR)/data/ft_split_destroy.c \
			   $(SOURCES_DIR)/data/ft_split_len.c \
			   $(SOURCES_DIR)/data/ft_split_edit.c \
			   $(SOURCES_DIR)/data/ft_split_del.c \
			   $(SOURCES_DIR)/data/ft_split_cpy.c \
			   $(SOURCES_DIR)/data/ft_split_add.c \
			   $(SOURCES_DIR)/data/ft_split_join.c \
			   $(SOURCES_DIR)/data/ft_split_merge.c \
			   $(SOURCES_DIR)/data/ft_putsplit.c \
			   $(SOURCES_DIR)/data/ft_putsplit_fd.c \
			   $(SOURCES_DIR)/data/ft_lstnew.c \
			   $(SOURCES_DIR)/data/ft_lstdelone.c \
			   $(SOURCES_DIR)/data/ft_lstdel.c \
			   $(SOURCES_DIR)/data/ft_lstadd.c \
			   $(SOURCES_DIR)/data/ft_lstiter.c \
			   $(SOURCES_DIR)/data/ft_lstmap.c \
			   $(SOURCES_DIR)/data/ft_lstdelstr.c \
			   $(SOURCES_DIR)/data/ft_lstdonothing.c \
			   $(SOURCES_DIR)/data/ft_lstbzero.c \
			   $(SOURCES_DIR)/data/ft_lststrrev.c \
			   $(SOURCES_DIR)/data/ft_lstaddtoend.c \
			   $(SOURCES_DIR)/data/ft_lsd_create.c \
			   $(SOURCES_DIR)/data/ft_lsd_insert.c \
			   $(SOURCES_DIR)/data/ft_lsd_insert_before.c \
			   $(SOURCES_DIR)/data/ft_lsd_push.c \
			   $(SOURCES_DIR)/data/ft_lsd_stack.c \
			   $(SOURCES_DIR)/data/ft_lsd_join.c \
			   $(SOURCES_DIR)/data/ft_lsd_copy.c \
			   $(SOURCES_DIR)/data/ft_lsd_rev.c \
			   $(SOURCES_DIR)/data/ft_lsd_delone.c \
			   $(SOURCES_DIR)/data/ft_lsd_del.c \
			   $(SOURCES_DIR)/data/ft_lsd_getfirst.c \
			   $(SOURCES_DIR)/data/ft_lsd_getlast.c \
			   $(SOURCES_DIR)/data/ft_lsd_getlen.c \
			   $(SOURCES_DIR)/data/ft_lsd_strcount.c \
			   $(SOURCES_DIR)/data/ft_lsd_intsearch.c \
			   $(SOURCES_DIR)/data/ft_lsd_putstr.c \
			   $(SOURCES_DIR)/data/ft_lsd_putnbr.c \
			   $(SOURCES_DIR)/data/ft_intarray_to_lsd.c \
			   $(SOURCES_DIR)/data/ft_bt_new.c \
			   $(SOURCES_DIR)/data/ft_bt_add.c \
			   $(SOURCES_DIR)/data/ft_bt_search.c \
			   $(SOURCES_DIR)/data/ft_bt_destroy.c \
			   $(SOURCES_DIR)/data/ft_htable_create.c \
			   $(SOURCES_DIR)/data/ft_htable_destroy.c \
			   $(SOURCES_DIR)/data/ft_htable_setdata.c \
			   $(SOURCES_DIR)/data/ft_htable_getdata.c \
			   $(SOURCES_DIR)/data/ft_htable_hash.c

SRCS_SORTS = \
				$(SOURCES_DIR)/sorts/ft_lsd_fusion_intsort.c \
				$(SOURCES_DIR)/sorts/ft_lsd_fusion_strsort.c

SRCS_PARSER = \
				 $(SOURCES_DIR)/parser/ft_lsd_parse_args.c

SRCS_UTILS = \

SRCS = $(SRCS_BASICS) $(SRCS_IO) $(SRCS_DATA) \
	   $(SRCS_SORTS) $(SRCS_PARSER) $(SRCS_UTILS)

OBJS_BASICS = $(SRCS_BASICS:.c=.o)
OBJS_IO = $(SRCS_IO:.c=.o)
OBJS_DATA = $(SRCS_DATA:.c=.o)
OBJS_SORTS = $(SRCS_SORTS:.c=.o)
OBJS_PARSER = $(SRCS_PARSER:.c=.o)
OBJS_UTILS = $(SRCS_UTILS:.c=.o)
OBJS = $(OBJS_BASICS) $(OBJS_IO) $(OBJS_DATA) \
	   $(OBJS_SORTS) $(OBJS_PARSER)

all: $(NAME)

%.o: %.c $(DEPENDENCIES_ALL)
	$(CC) -c $< -o $@ $(CFLAGS) -I ./$(INCLUDES_DIR)

$(NAME): $(OBJS)
	@echo Creating $(NAME)...
	@ar rcs $(NAME) $(OBJS)

$(NAME_BASICS): $(OBJS_BASICS)
	@echo Creating $(NAME_BASICS)...
	@ar rcs $(NAME_BASICS) $(OBJS_BASICS)

$(NAME_IO): $(OBJS_IO)
	@echo Creating $(NAME_IO)...
	@ar rcs $(NAME_IO) $(OBJS_IO)

$(NAME_DATA): $(OBJS_DATA)
	@echo Creating $(NAME_DATA)...
	@ar rcs $(NAME_DATA) $(OBJS_DATA)

$(NAME_SORTS): $(OBJS_SORTS)
	@echo Creating $(NAME_SORTS)...
	@ar rcs $(NAME_SORTS) $(OBJS_SORTS)

$(NAME_PARSER): $(OBJS_PARSER)
	@echo Creating $(NAME_PARSER)...
	@ar rcs $(NAME_PARSER) $(OBJS_PARSER)

$(NAME_UTILS): $(OBJS_UTILS)
	@echo Creating $(NAME_UTILS)...
	@ar rcs $(NAME_UTILS) $(OBJS_UTILS)

clean:
	@rm -f $(OBJS) $(OBJS_UTILS)
	@echo Deleting $(NAME) OBJECTS files...

fclean: clean
	@rm -f $(ALLNAME)

	@echo Deleting $(NAME)...

re: fclean all
re$(NAME_BASICS): fclean $(NAME_BASICS)
re$(NAME_IO): fclean $(NAME_IO)
re$(NAME_DATA): fclean $(NAME_DATA)
re$(NAME_SORTS): fclean $(NAME_SORTS)
re$(NAME_PARSER): fclean $(NAME_PARSER)
re$(NAME_UTILS): fclean $(NAME_UTILS)

.PHONY: clean fclean re all

