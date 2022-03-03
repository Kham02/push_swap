#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../Libft/libft.h"
// #include "../gnl_nb/get_next_line.h"
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
	int		size_b;
	int		i;
	int		j;
	int		min;
	int		max;
	int		mid;
	int		next_order;
	int		val_bub;
	int		count;
}t_data;

typedef struct s_list
{
	int				val;
	int				order;
	int				flag;
	struct s_list	*next;
}t_list;



int		main(int ac ,char **av);
void	check(t_data *data, int ac, char **av);
void	values(t_data *data);
void	check_valid(t_data *data);
int		push_swap_atoi(t_data *data, unsigned int n, int s);
char	error(t_data *data);
void	free2arr(char **str);
int		check_sort(t_data *data);
int		check_sort2(t_data *data);
#endif