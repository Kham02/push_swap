/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:49 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 21:05:11 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_atoi(char *str, unsigned int n, int s)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		data->j++;
		s = -1;
	}
	if (str[i] == '+' && s == 1)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
	}
	return(n * s);
}

int	check_sort(t_data *data)
{
	data->i = 0;
	data->size_a = size_stack(data->a_stack);
	while (data->i < data->size_a)
	{
		if (data->a_stack->val > data->a_stack->next->val)
			return(1);
		data->a_stack = data->a_stack->next;
		data->i++;
	}
	return(0);
}

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
	data->stack = stack;
	order(data);
}

void	order(t_data *data)
{
	t_listp	stack2;

	stack2 = data->a_stack;
	data->i = 0;
	data->size_a = size_stack(data->a_stack);
	while (data->i < data->size_a)
	{
		data->j = 0;
		while (data->j < data->size_a)
		{
			if (stack2->val == data->stack->val)
			{
				data->stack = data->stack->next;
				data->stack->order = data->j + 1;
			}
			data->j++;
		}
		stack2 = stack2->next;
		data->i++;
	}
}