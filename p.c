#include "push_swap.h"

//сверху а наверх б
void	pa(t_data *data)
{
	t_list	list1;
	t_list	list2;

	list1 = data->a_stack;
	list2 = data->b_stack;
	data->b_stack = data->b_stack->next;
	data->a_stack = list2;
	data->a_stack = list1;
	free_list(list1);
	free_list(list2);
	ft_putstr_fd("pa\n", 1);
}

//сверху б наверх а
void	pb(t_data *data)
{
	t_list	list1;
	t_list	list2;

	list1 = data->a_stack;
	list2 = data->b_stack;
	data->a_stack = data->a_stack->next;
	data->b_stack = list1;
	data->b_stack = list2;
	free_list(list1);
	free_list(list2);
	ft_putstr_fd("pb\n", 1);
}
