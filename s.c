#include "push_swap.h"

//в а поменять местами верхние два элемента
void	sa(t_data *data)
{
	t_list	list1;
	t_list	list2;

	list1 = data->a_stack;
	list2 = data->a_stack->next;
	data->a_stack = list2;
	list2->next = data->a_stack->next;
	data->a_stack->next = list1;
}

//в б поменять местами верхние два элемента
void	sb(t_data *data)
{

}

//вместе sa sb
void	ss(t_data *data)
{
	
}