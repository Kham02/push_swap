/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:31:41 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 21:47:25 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_utils(t_data *data)
{
	data->size_b = size_stack(data->b_stack);
	data->mid = data->size_b / 2;
	data->mid += data->next_order;
	while (data->size_b >= 0)
	{
		if (data->b_stack->order >= data->mid)
		{
			data->b_stack->flag = 2;
			pa(data);
		}
		else
			rb(data);
		data->size_b--;
	}
}

// void	opt_sort_b(t_data *data)
// {
// 	if (lst_last(data->b_stack)->order == data->next_order)
// 	{
// 		rrb(data);
// 		data->b_stack->flag = 1;
// 		pa(data);
// 		ra(data);
// 		data->next_order++;
// 	}
// 	else if (data->b_stack->order == data->next_order)
// 	{
// 		data->b_stack->flag = 1;
// 		pa(data);
// 		ra(data);
// 		data->next_order++;
// 	}
// 	else
// 		rb(data);
// }

void	sort_a_utils(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	while (data->a_stack->order == data->next_order)
	{
		data->a_stack->flag = 1;
		ra(data);
		data->next_order++;
	}
	while (data->a_stack->flag == 2 && data->size_a >= 0)
	{
		pb(data);
		data->size_a--;
	}
}

// void	scroll_up(t_data *data)
// {
// 	while (data->size_a >= 0 && data->size_b >= 0)
// 	{
// 		if (lst_last(data->a_stack)->flag == 0 && lst_last(data->b_stack)->order != data->next_order)
// 			rrr(data);
// 		else
// 			break;
// 		data->size_a--;
// 		data->size_b--;
// 	}
// 	while (data->size_a >= 0)
// 	{
// 		if (lst_last(data->a_stack)->flag == 0)
// 			rra(data);
// 		else
// 			break;
// 		data->size_a--;
// 	}
// }

// void	search_next_order(t_listp *lst)
// {
// 	t_listp	*list;

// 	lst = 
// }