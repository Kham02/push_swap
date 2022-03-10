#include "push_swap.h"

// void	insertion_sort(t_data *data)
// {
// 	data->i = 0;
// 	data->j = 0
// 	data->size_a = ft_lstsize(data->a_stack);
// 	while (data->i <= data->size_a)
// 	{
// 		data->j = data->i;
// 		while (data->j > 0 && data->a_stack->val > )
// 		{
// 			//
// 		}
// 	}
// 	check_sort(t_data *data);
// }

void	sort_two(t_data *data)
{
	if (data->a_stack->val > data->a_stack->next->val)
		sa(data);
}

void	sort_els(t_data *data)
{
	int	a;
	int	b;
	int	c;

	if (data->size_a == 2)
		sort_two(data);
	a = data->a_stack->val;
	b = data->a_stack->next->val;
	c = ft_lstlast(data->a_stack)->next;
	if (ft_lstsize(data->a_stack) != 3 || (a < b && b < c))
		return ;
	if ((a < b && b > c && a > c) || (a > b && b < c && a < c))
		sa(data);
	else if ((a < b && b > c && a < c))
		ra(data);
	a = data->a_stack->val;
	b = data->a_stack->next->val;
	c = ft_lstlast(data->a_stack)->next;
	if ((a > b && b < c && a > c) || (a > b && b > c && a > c))
	{
		ra(data);
		if (a > b && b > c && a > c)
			sa(data);
	}
}

void	sort_min(t_data *data)
{
	int	i;

	i = 0;
	if (data->size_a > 3)
	{
		while (i < data->size_a - 2)
		{
			if (data->a_stack->val > 2)
			{
				i++;
				pb(data);
			}
			else
				ra(data);
		}
	}
	sort_3_els(data);
	sort_4_el(data);
}