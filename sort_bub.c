/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:38 by estrong           #+#    #+#             */
/*   Updated: 2022/03/12 14:26:37 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bub(t_data *data)
{
	data->str_int = data->a_stack->val;
	data->i = 1;
	while (data->i <= data->size_b)
	{
		if (data->str_int[data->i - 1] > data->str_int[data->i])
		{
			data->val_bub = data->str_int[data->i - 1];
			data->str_int[data->i - 1] = data->str_int[data->i];
			data->str_int[data->i] = data->val_bub;
			if (data->str_int[data->i - 1] == data->str_int[data->i])
				error(data);
		}
		data->i++;
	}
}

void	order(t_data *data)
{
	data->stack = data->a_stack;
	data->i = 0;
	while (data->i < data->size_a)
	{
		data->j = 0;
		while (data->j < data->size_a)
		{
			if (data->stack->val = data->str_int[data->j])
				data->stack->order = data->j + 1;
			data->j++;
		}
		data->stack = data->stack->next;
		data->i++;
	}
	data->b_stack->order = data->stack->order;
}