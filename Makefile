# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez <snunez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:44:31 by snunez            #+#    #+#              #
#    Updated: 2022/03/22 11:44:32 by snunez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra 

SRCS = so_long.c parsemap.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

UNAME := $(shell uname -s)

MLX_PATH = minilibx_linux/

LIBFT_PATH = Libft/

LIBFT = -L$(LIBFT_PATH) $(LIBFT_PATH)libft.a

ifeq ($(UNAME),Darwin)
	MINILIBX:= -lmlx -framework OpenGL -framework AppKit
else
	MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx
endif

$(NAME) :	mlx libft $(OBJS)
			make clean -sC $(LIBFT_PATH)
##			make clean -sC $(MLX_PATH)
			$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)

all:	$(NAME)

libft:
		make -C $(LIBFT_PATH)

mlx:
		make -C $(MLX_PATH)

clean:
		make clean -sC $(LIBFT_PATH)
		make clean -sC $(MLX_PATH)
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY = all clean fclean re

