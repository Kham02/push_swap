/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:45 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 20:00:17 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	qs(t_data *data)
// {
// 	data->mid = data->size_a / 2;
// 	data->i = 0;
// 	while (data->i <= data->size_a)
// 	{
// 		if (data->a_stack->val <= data->mid)
// 			pb(data);
// 		else
// 			ra(data);
// 		data->i++;
// 	}
// 	start_sort_b(data);
// }

// void	start_sort_b(t_data *data)
// {
// 	data->max = data->mid;
// 	data->mid = (data->max - data->next_order) / 2 + data->next_order;
// 	data->i = 0;
// 	sort_b(data);
// 	data->size_b = size_stack(data->b_stack);
// 	if (data->size_b > 0)
// 		sort_b(data);
// 	sort_a(data);
// }

// void	sort_b(t_data *data)
// {
	print(data->a_stack);
	printf("-----stack_b-----\n");
	print(data->b_stack);
// 	data->size_b = size_stack(data->b_stack);
// 	while (data->i < data->size_b)
// 	{
// 		if (data->b_stack->order == data->next_order)
// 		{
// 			pa(data);
// 			ra(data);
// 			data->next_order++;
// 		}
// 		else
// 			rb(data);
// 		data->i++;
// 	}
// }

// void	sort_a(t_data *data)
// {
// 	while (data->a_stack->flag > 0)
// 	{
// 		if (data->a_stack->flag == data->next_order)
// 		{
// 			ra(data);
// 			data->next_order++;
// 		}
// 		else
// 			pb(data);
// 	}
// 	data->size_b = size_stack(data->b_stack);
// 	if (data->size_b > 0)
// 	{
// 		// search_mid(data);
// 		start_sort_b(data);
// 	}
// }

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
}

void	sort_b(t_data *data)
{
	data->size_b = size_stack(data->b_stack);
	data->mid = data->b_stack / 2;
	while(data->size_b >= 0)
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
	if (size_stack(data->b_stack) > 0)
		sort_b(data);
}
