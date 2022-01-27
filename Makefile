NAME	=	push_swap

SRCS	=	push_swap.c	

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