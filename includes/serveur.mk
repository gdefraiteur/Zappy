# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    serveur.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/04 13:00:04 by npineau           #+#    #+#              #
#    Updated: 2014/06/06 14:08:04 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSRV	:=	server_channel.c \
			server_check_fd.c \
			server_clean_fd.c \
			server_client_add.c \
			server_client_read.c \
			server_client_write.c \
			server_command.c \
			server_do_select.c \
			server_get_opt.c \
			server_init_env.c \
			server_init_fd.c \
			server_main.c \
			server_main_loop.c \
			server_nick.c \
			server_private_message.c \
			server_srv_accept.c \
			server_srv_create.c \
			server_x.c
