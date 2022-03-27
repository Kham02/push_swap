#ifndef CHECKER_H
#define CHECKER_H

#include "../Libft/libft.h"

typedef struct s_listp
{
	int				val;
	int				order;
	int				flag;
	struct s_listp	*next;
}t_listp;

typedef struct s_data
{
	t_listp	*a_stack;
	t_listp	*b_stack;
}t_data;

int		size_stack(t_listp *lst);
t_listp	*lst_new(int val);
void	lst_add_back(t_listp **lst, t_listp *new_lst);
void	check_valid(t_data *data, char **av);
int		check_dub(char **av);
int		ft_strcmp(char *s1, char *s2);
int		check_sort(t_data *data);
int	push_swap_atoi(t_data *data, char *str, unsigned int n, int s);
void	reed_op(t_data *data);
void	check_op(t_data *data, char *str);
void	error(t_data *data);
void	end(t_data *data);

#endif