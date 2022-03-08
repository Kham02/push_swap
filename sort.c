#include "push_swap.h"

void	qs(t_data *data)
{
	data->mid = data->size_a / 2;
	data->i = 0;
	while (data->i <= data->size_a)
	{
		if (data->a_stack->val <= data->mid)
			PUSH_B;
		else
			ROTATE_A;
		data->i++;
	}
	sort_b(t_data *data);
}

void	recursion_b(t_data *data)
{
	data->max = data->mid;
	data->mid = (data->max - data->next_order) / 2 + data->next_order;
	data->i = 0;
	sort_b(data);
	data->size_b = ft_lstsize(data->b_stack);
	if (data->size_b > 0)
	{
		sort_b(data);
		data->f++;
	}
	sort_a(data);
}

void	sort_b(t_data *data)
{
	data->size_b = ft_lstsize(data->b_stack);
	while (data->i < data->size_b)
	{
		if (data->b_stack->order > data->mid)
		{
			data->b_stack->flag = data->f;
			ROTATE_A;
		}
		else
		{
			if (data->b_stack->order == data->next_order)
			{
				PUSH_A;
				ROTATE_A;
				data->next_order++;
			}
			else
				ROTATE_B;
		}
		data->i++;
	}
}

void	sort_a(t_data *data)
{
	while (data->a_stack->flag > 0)
	{
		if (data->a_stack->flag == data->next_order)
		{
			ROTATE_A;
			data->next_order++;
		}
		else
			PUSH_B;
	}
	data->size_b = ft_lstsize(data->b_stack);
	if (data->size_b > 0)
	{
		search_mid(data);
		recursion_b(data);
	}
}
