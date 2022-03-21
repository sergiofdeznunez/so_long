# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez <snunez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:44:31 by snunez            #+#    #+#              #
#    Updated: 2022/03/21 13:51:54 by snunez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra 

SRCS = so_long.c parsemap.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

UNAME := $(shell uname)

MLX_DIR = ./minilibx_opengl/minilibx_opengl

$(NAME) :	$(OBJS)
##		ifeq ($(UNAME), Linux)
##			make -sC $(MLX_DIR)
##			make clean -sC $(MLX_DIR)
##			$(CC) $(CFLAGS) $(OBJS) -L $(MLX_DIR) $(MLX_DIR)libmlx.a -o $(NAME)
##		else
			$(NAME) :	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGL -framework Appkit -o $(NAME)
##		endif

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY = all clean fclean re

