# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 14:00:04 by estrong           #+#    #+#              #
#    Updated: 2022/04/01 20:01:18 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_B	= checker

HEAD 	= push_swap.h

HEAD_B	= ./bonus/checker_bonus.h

LIST	=	push_swap.c	err.c	p.c	r.c	rr.c	s.c	\
			sort_min.c	sort2_0.c	valid.c	utils_lst.c	\
			sort_utils2_0.c

LIST_B	=	./bonus/checker_bonus.c	./bonus/get_next_line_bonus.c	./bonus/get_next_line_utils_bonus.c	\
			./bonus/mov_operations_bonus.c	./bonus/p_bonus.c	./bonus/s_bonus.c	./bonus/r_bonus.c	\
			./bonus/rr_bonus.c	./bonus/utils_list_bonus.c	./bonus/utils_bonus.c	./bonus/valid_bonus.c
			

OBJ = $(patsubst %.c,%.o,$(LIST))

OBJ_B = $(patsubst %.c,%.o, $(LIST_B))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(HEAD)
	make -C ./libft
	gcc -c ${FLAGS} ${LIST} -I libft/
# gcc -g -c ${LIST} -I libft/
	gcc ${OBJ} libft/libft.a -o ${NAME} 

bonus : $(OBJ_B) $(HEAD_B)
	make -C ./libft
# gcc -c ${FLAGS} ${LIST_B} -I libft/
	gcc ${OBJ_B} libft/libft.a -o ${NAME_B}
# @rm -f *.o

clean :
	rm -f $(OBJ) $(OBJ_B)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME) $(NAME_B)
	make fclean -C ./libft

re : fclean all