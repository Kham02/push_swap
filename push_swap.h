#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../Libft/libft.h"
#include "../gnl_nb/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_data
{
	t_list	a_stack;
	t_list	b_stack;
	t_list	stack;
	char	*str;
	char	*str2;
	int		*str_int;
	int		size_a;
	int		i;
	int		j;
	int		min;
	int		max;
	int		mid;
	int		next_order;
	
}t_data;

typedef struct s_list
{
	int	val;
	int	order;
	int	flag;
	int	*next;
	int	*prev;
}t_list;



int		main(int ac ,char **av);
void	check(t_data *data, int ac, char **av);
void	values(t_data *data);
void	check_valid(t_data *data);
int		push_swap_atoi(t_data *data, unsigned int n, int s);
char	error(t_data *data);
void	free(char **str);
int		check_sort(t_data *data);

#endif