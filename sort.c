/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:45 by estrong           #+#    #+#             */
/*   Updated: 2022/03/23 13:08:34 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	data->mid = (data->size_a - data->next_order) / 2;
	data->fl = 0;
	while (data->size_a > 0)
	{
		if (data->a_stack->val <= data->mid)
			pb(data);
		else
			ra(data);
		data->size_a--;
	}
	sort_b(data);
	// print(data->a_stack);
	// printf("-----stack_b-----\n");
	// print(data->b_stack);
}

void	sort_b(t_data *data)
{
	data->size_b = size_stack(data->b_stack);
	data->mid = data->size_b / 2;
	while(data->size_b > 0)
	{
		if(data->b_stack->order == data->next_order)
		{
			data->b_stack->flag++;
			pa(data);
			ra(data);
			data->next_order++;
		}
		else
			rb(data);
		data->size_b--;
	}
	if (size_stack(data->b_stack) > 0)
		sort_b(data);
	data->fl++;
	sort_a(data);
}

void	sort_a(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	data->mid = (data->size_a - data->next_order) /2;
	while (data->size_a > 0)
	{
		if (data->a_stack->val <= data->mid)
			pb(data);
		else
			ra(data);
	}
	scroll(data);
	if (size_stack(data->b_stack) > 0)
		sort_b(data);
}

void	scroll(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	data->size_b = size_stack(data->b_stack);
	while (data->size_a > 0 && data->size_b > 0)
	{
		if (data->a_stack->flag != 0 && data->b_stack->order != data->next_order)
			rr(data);
		data->size_a--;
		data->size_b--;
	}
	while (data->size_a > 0)
	{
		if (data->a_stack->flag != 0)
			ra(data);
		data->size_a--;
	}
}
