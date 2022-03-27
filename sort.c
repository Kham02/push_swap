/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:45 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 21:47:42 by estrong          ###   ########.fr       */
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
	}
	sort_b(data);
	if (size_stack(data->b_stack) <= 0 && check_sort(data) > 0)
		sort_b(data);
	// print(data->a_stack);
	// print(data->b_stack);
}

void	sort_b(t_data *data)
{
	data->size_b = size_stack(data->b_stack);
	if (data->b_stack->flag == 0)
		sort_b_utils(data);
	while (data->size_b >= 0)
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
		// if (size_stack(data->b_stack) < 0)
		// 	break;
		data->size_b--;
	}
	sort_a(data);
	if (size_stack(data->b_stack) >=0)
		sort_b(data);

}

void	sort_a(t_data *data)
{
	sort_a_utils(data);
	data->size_a = size_stack(data->a_stack);
	data->mid = data->size_a / 2;
	data->mid += data->next_order;
	while (data->a_stack->flag == 0 && data->size_a >= 0)
	{
		if (data->a_stack->order <= data->mid)
			pb(data);
		else
			ra(data);
		data->size_a--;
	}
	if (check_sort(data) == 1)
		scroll(data);
}

void	scroll(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	data->size_b = size_stack(data->b_stack);
	// if (data->next_order > data->size_a - data->next_order)
		// scroll_up(data);
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
