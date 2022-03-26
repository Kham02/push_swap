/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:45 by estrong           #+#    #+#             */
/*   Updated: 2022/03/26 20:22:58 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	data->mid = (data->size_a) / 2;
	while (data->size_a >= 0)
	{
		if (data->a_stack->order <= data->mid)
			pb(data);
		else
			ra(data);
		data->size_a--;
		// debug_print(&data->a_stack, &data->a_stack);
		// debug_print(&data->a_stack, &data->b_stack);
	}
	sort_b(data);
	while (size_stack(data->b_stack) >= 0 && check_sort(data) != 0)
	{
		// printf("%d\n", check_sort(data));
		// printf("%d\n", size_stack(data->b_stack));
		sort_b(data);
	}
	// print(data->a_stack);
	// write(1, "4\n", 2);
	// print(data->b_stack);
}

void	sort_b(t_data *data)
{
	if (data->b_stack->flag == 0)
		sort_b_utils(data);
	while (size_stack(data->b_stack) >= 0)
	{
		if (data->b_stack->order == data->next_order)
		{
			data->b_stack->flag = 1;
			pa(data);
			ra(data);
			data->next_order++;
		}
		else
			rb(data);
	}
	sort_a(data);
	// print(data->b_stack);
}

void	sort_a(t_data *data)
{
	// print(data->a_stack);
	sort_a_utils(data);
	data->size_a = size_stack(data->a_stack);
	data->mid = (data->size_a - data->next_order) / 2 + data->next_order;
	while (data->a_stack->flag == 0 && data->size_a >= 0)
	{
		// write(1, "rt\n", 3);
		if (data->a_stack->order <= data->mid)
			pb(data);
		else
			ra(data);
		data->size_a--;
	}
	// if (check_sort(data) == 0)
	// 	end(data);
	// print(data->a_stack);
	if (data->a_stack->flag == 1)
		scroll(data);
}

void	scroll(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	data->size_b = size_stack(data->b_stack);
	while (data->size_a >= 0 && data->size_b >= 0)
	{
		if (data->a_stack->flag == 1 && data->b_stack->order != data->next_order)
			rr(data);
		else
			break;
		data->size_a--;
		data->size_b--;
	}
	while (data->size_a >= 0)
	{
		if (data->a_stack->flag == 1)
			ra(data);
		else
			break;
		data->size_a--;
	}
}
