# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 14:00:04 by estrong           #+#    #+#              #
#    Updated: 2022/03/31 18:24:33 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_B	= checker

HEAD 	= push_swap.h

HEAD_B	= ./bonus/checker.h

LIST	=	push_swap.c	err.c	p.c	r.c	rr.c	s.c	\
			sort_min.c	sort2_0.c	valid.c	utils_lst.c	\
			sort_utils2_0.c

LIST_B	=	bonus/checker.c	bonus/get_next_line.c	bonus/get_next_line_utils.c	\
			bonus/mov_operations.c	bonus/p.c	bonus/s.c	bonus/r.c	\
			bonus/rr.c	bonus/utils_list.c	bonus/utils.c	bonus/valid.c
			

OBJ = $(patsubst %.c,%.o,$(LIST))

OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(HEAD)
	make -C ./libft
	gcc -c ${FLAGS} ${LIST} -I libft/
# gcc -g -c ${LIST} -I libft/
	gcc ${OBJ} libft/libft.a -o ${NAME} 

bonus : $(OBJ_B) $(HEAD_B)
	make -C ./libft
	gcc -c ${FLAGS} ${LIST_B} -I libft/
	gcc ${OBJ_B} -o ${NAME_B} libft/libft.a
clean :
	rm -f $(OBJ) $(OBJ_B)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME) $(NAME_B)
	make fclean -C ./libft
re : fclean all