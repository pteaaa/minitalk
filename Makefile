# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tperes <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 14:51:54 by tperes            #+#    #+#              #
#    Updated: 2022/04/04 21:39:47 by tperes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRC1 = server.c

SRC2 = client.c

OBJ1 = ${SRC1:.c=.o}

OBJ2 = ${SRC2:.c=.o}

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJ1}
		cd libft && ${MAKE} bonus
		cp libft/libft.a .
		${CC} ${FLAGS} -o ${SERVER} ${OBJ1} libft.a

${CLIENT}: ${OBJ2}
		cd libft && ${MAKE} bonus
		cp libft/libft.a .
		${CC} ${FLAGS} -o ${CLIENT} ${OBJ2} libft.a

%.o :%.c
	$(CC) -c $(FLAGS) -Ilibft/ $< -o $@

clean:
		rm -f ${OBJ1} ${SERVER} ${OBJ2} ${CLIENT}
		${MAKE} clean -C ./libft

fclean: clean
		rm -f libft.a
		${MAKE} fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
