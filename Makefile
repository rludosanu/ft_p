# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rludosan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 10:26:56 by rludosan          #+#    #+#              #
#    Updated: 2017/05/16 16:15:06 by rludosan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_UTILS		=	libutils.a
EXEC_SERVEUR	=	serveur
EXEC_CLIENT		=	client

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

DIR_UTILS		=	./src_utils/
DIR_SERVEUR		=	./src_serveur/
DIR_CLIENT		=	./src_client/

SRC_UTILS		=	ft_printf \
					ft_putchar \
					ft_putstr \
					ft_strlen \
					ft_strsplit \
					ft_arrdel \
					ft_strcmp \
					ft_atoi \
					ft_itoa \
					ft_strdup \
					ft_memset \
					ft_putnbr \
					ft_puthex \
					ft_strnew \
					ft_file_exists \
					ft_btof \
					ft_getcwd \
					ft_itoa \
					ft_putstrcmp \
					ft_strnequ \
					ft_strchr \
					ft_arrlen \
					ft_strcat \
					ft_strdcat \
					ft_strisempty \
					ft_strreplace \
					read_msg \
					send_msg \
					is_ready

SRC_SERVEUR		=	ft_serveur \
					server_handle \
					server_create \
					server_error \
					server_clt \
					server_get \
					server_put \
					server_pwd \
					server_ls \
					server_cd

SRC_CLIENT		=	ft_client \
					client_handle \
					client_dialog \
					client_get \
					client_put \
					client_lls \
					client_lpwd \
					client_lcd \
					client_pwd \
					client_ls \
					client_cd

OBJ_UTILS		=	$(addsuffix .o, $(SRC_UTILS))
OBJ_SERVEUR		=	$(addsuffix .o, $(SRC_SERVEUR))
OBJ_CLIENT		=	$(addsuffix .o, $(SRC_CLIENT))

TGT_UTILS		=	$(addprefix $(DIR_UTILS), $(OBJ_UTILS))
TGT_SERVEUR		=	$(addprefix $(DIR_SERVEUR), $(OBJ_SERVEUR))
TGT_CLIENT		=	$(addprefix $(DIR_CLIENT), $(OBJ_CLIENT))

all: $(LIB_UTILS) $(EXEC_SERVEUR) $(EXEC_CLIENT)

$(LIB_UTILS): $(TGT_UTILS)
	ar rc $@ $^
	ranlib $@

$(EXEC_SERVEUR): $(TGT_SERVEUR)
	$(CC) $(CFLAGS) -Iinc -o $@ $^ $(LIB_UTILS)

$(EXEC_CLIENT): $(TGT_CLIENT)
	$(CC) $(CFLAGS) -Iinc -o $@ $^ $(LIB_UTILS)

%.o: %.c
	$(CC) $(CFLAGS) -Iinc -o $@ -c $<

clean:
	rm -f $(TGT_UTILS) $(TGT_SERVEUR) $(TGT_CLIENT)

fclean: clean
	rm -rf $(LIB_UTILS) $(EXEC_SERVEUR) $(EXEC_CLIENT)

re: fclean all

.PHONY: all clean fclean re
