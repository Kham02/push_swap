/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:45 by estrong           #+#    #+#             */
/*   Updated: 2022/03/12 22:45:27 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	qs(t_data *data)
{
	data->mid = data->size_a / 2;
	data->i = 0;
	while (data->i <= data->size_a)
	{
		if (data->a_stack->val <= data->mid)
			pb(data);
		else
			ra(data);
		data->i++;
	}
	recursion_b(*data);
}

void	recursion_b(t_data *data)
{
	data->max = data->mid;
	data->mid = (data->max - data->next_order) / 2 + data->next_order;
	data->i = 0;
	data->f = 0;
	sort_b(data);
	data->size_b = size_stack(data->b_stack);
	if (data->size_b > 0)
	{
		sort_b(data);
		data->f++;
	}
	sort_a(data);
}

void	sort_b(t_data *data)
{
	data->size_b = size_stack(data->b_stack);
	while (data->i < data->size_b)
	{
		if (data->b_stack->order == data->next_order)
		{
			pa(data);
			ra(data);
			data->next_order++;
		}
		else
			rb(data);
		data->i++;
	}
}

void	sort_a(t_data *data)
{
	while (data->a_stack->flag > 0)
	{
		if (data->a_stack->flag == data->next_order)
		{
			ra(data);
			data->next_order++;
		}
		else
			pb(data);
	}
	data->size_b = size_stack(data->b_stack);
	if (data->size_b > 0)
	{
		// search_mid(data);
		recursion_b(data);
	}
}

// void	search_mid(t_data *data)
// {

// }
