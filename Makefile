# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunez <snunez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:44:31 by snunez            #+#    #+#              #
#    Updated: 2022/03/03 14:33:55 by snunez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra 

SRCS = so_long.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -I /usr/local/include -L /usr/local/lib -l mlx -framework OpenGL -framework Appkit -o $(NAME)
			
all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY = all clean fclean re

