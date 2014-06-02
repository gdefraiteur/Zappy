# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2014/06/02 15:48:50 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fckoff
CLIENT	:=	client
SERVEUR	:=	serveur
GFX		:=	gfx

### DIRECTORIES ###

DIRSRC	:=	sources
DIRSRV	:=	$(DIRSRC)/$(SERVEUR)
DIRCLI	:=	$(DIRSRC)/$(CLIENT)
DIRGFX	:=	$(DIRSRC)/$(GFX)
DIROBJ	:=	objects
DIRINC	:=	includes
DIRLIB	:=	libft

### FILES ###

SRCCLI	:=	

SRCSRV	:=	

SRCGFX	:=	

OBJCLI	:=	$(SRCCLI:.c=.o)
OBJSRV	:=	$(SRCSRV:.c=.o)
OBJGFX	:=	$(SRCGFX:.c=.o)

HEADCLI	:=	client.h
HEADSRV	:=	server.h
HEADGFX	:=	gfx.h
LIB		:=	libft.a

### PATHS ###

POBJCLI		:=	$(addprefix $(DIROBJ)/, $(OBJCLI))
POBJSRV		:=	$(addprefix $(DIROBJ)/, $(OBJSRV))
POBJGFX		:=	$(addprefix $(DIROBJ)/, $(OBJGFX))

PHEADCLI	:=	$(DIRINC)/$(HEADCLI)
PHEADSRV	:=	$(DIRINC)/$(HEADSRV)
PHEADGFX	:=	$(DIRINC)/$(HEADGFX)
PLIB		:=	$(DIRLIB)/$(LIB)

### COMPILATION VARIABLES ###

CC		:=	llvm-gcc
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC)

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(PLIB) $(SERVEUR) $(CLIENT) $(GFX)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJSRV): |$(DIROBJ)

$(POBJCLI): |$(DIROBJ)

$(POBJGFX): |$(DIROBJ)

$(DIROBJ)/%.o: $(DIRCLI)/%.c $(PHEADCLI)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRSRV)/%.c $(PHEADSRV)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRGFX)/%.c $(PHEADGFX)
	$(COMPIL)

### EXECUTABLE ###

$(NAME):
	echo $(NAME)

$(CLIENT): $(POBJCLI)
	$(LINK)

$(SERVEUR): $(POBJSRV)
	$(LINK)

$(GFX): $(POBJGFX)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVEUR) $(GFX)

re: fclean all
