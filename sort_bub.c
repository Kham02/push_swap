/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:38 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 14:44:35 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bub(t_data *data) 
{
	t_listp	*stack;

	stack = data->a_stack;
	data->i = 0;
	while (data->i < size_stack(stack))
	{
		if (stack->val > stack->next->val)
		{
			data->val_bub = stack->val;
			stack->val = stack->next->val;
			stack->next->val = data->val_bub;
			if (stack->val == stack->next->val)
				error(data);
		}
		data->i++;
	}
	// write(1, "b\n", 2);
	data->stack = stack;
}

void	order(t_data *data)
{
	data->stack = data->a_stack;
	data->i = 0;
	while (data->i < size_stack(data->a_stack))
	{
		data->j = 0;
		while (data->j < data->size_a)
		{
			if (data->stack->val == data->str_int[data->j])
				data->stack->order = data->j + 1;
			data->j++;
		}
		data->stack = data->stack->next;
		data->i++;
	}
	data->b_stack->order = data->stack->order;
}