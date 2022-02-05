#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../Libft/libft.h"
#include "../gnl_nb/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_data
{
	t_all	a_stack;
	t_all	b_stack;
	int		i;
	int		min;
	int		max;
	int		mid;
}t_data;

typedef struct s_list
{
	int	val;
	int	order;
	int	flag;
	int	*next;
	int	*prev;
}t_list;



int	main(int ac ,char **av);

#endif