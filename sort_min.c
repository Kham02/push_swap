#include "push_swap.h"

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