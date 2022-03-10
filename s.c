#include "push_swap.h"

//в а поменять местами верхние два элемента
void	sa(t_data *data)
{
	t_list	list1;
	t_list	list2;

	list1 = data->a_stack;
	list2 = data->a_stack->next;
	list1->next = data->a_stack->next->next;
	data->a_stack = list2;
	data->a_stack->next = list1;
	free_list(list1);
	free_list(list2);
	ft_putstr_fd("sa\n", 1);
}

//в б поменять местами верхние два элемента
void	sb(t_data *data)
{
	t_list	list1;
	t_list	list2;

	list1 = data->b_stack;
	list2 = data->b_stack->next;
	list1->next = data->b_stack->next->next;
	data->b_stack = list2;
	data->b_stack->next = list1;
	free_list(list1);
	free_list(list2);
	ft_putstr_fd("sb\n", 1);
}

//вместе sa sb
void	ss(t_data *data)
{
	ft_putstr_fd("ss\n", 1);
}