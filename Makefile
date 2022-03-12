# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 14:00:04 by estrong           #+#    #+#              #
#    Updated: 2022/03/12 15:24:53 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c	err.c	p.c	r.c	rr.c	s.c	\
			sort_bub.c	sort_min.c	sort.c	valid.c

OBJ		=	$(patsubst %.c,%.o,$(SRCS))

HEADER	=	push_swap.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY :	all clean fclean re

all :	$(NAME)

$(NAME) :
	$(MAKE) -C ./libft
	$(CC) -c ${FLAGS} ${SRCS} -I libft/
	$(CC) ${OBJ} -o ${NAME} libft/libft.a

clean :
	rm -f $(OBJ)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft
re : fclean all