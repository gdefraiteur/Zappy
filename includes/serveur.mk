# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    serveur.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/04 13:00:04 by npineau           #+#    #+#              #
#    Updated: 2014/06/06 17:16:58 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSRV	:=	server_check_fd.c \
			server_clean_fd.c \
			server_client_add.c \
			server_client_unknown.c \
			server_client_write.c \
			server_do_select.c \
			server_get_opt.c \
			server_init_env.c \
			server_init_fd.c \
			server_main.c \
			server_main_loop.c \
			server_srv_accept.c \
			server_srv_create.c \
			server_x.c
