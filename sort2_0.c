/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:55:44 by estrong           #+#    #+#             */
/*   Updated: 2022/03/30 16:02:18 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	data->max = data->size_a;
	data->mid = (data->size_a) / 2;
	while (size_stack(data->a_stack) != 2)
	{
		if (data->a_stack->order > data->mid && data->a_stack->order != 0 \
		&& data->a_stack->order != data->max)
		{
			pb(data);
			rb(data);
		}
		else if (data->a_stack->order < data->mid && data->a_stack->order != 0 \
		&& data->a_stack->order != data->min)
			pb(data);
		else
			ra(data);
	}
}

void	push_a(t_data *data)
{
	t_listp	*lst_mov;

	lst_mov = data->b_stack;
	init_cost(data);
	while (lst_mov != data->min_mov)
		lst_mov = lst_mov->next;
	data->next_order = lst_mov->order;
	if (lst_mov->flag == 1 || lst_mov->cost_a == -1)
		rr_scroll(data, lst_mov);
	else
		r_scroll(data, lst_mov);
	if (data->a_stack->order > data->next_order && data->b_stack == lst_mov)
		pa(data);
	print(data->a_stack);
	print(data->b_stack);
	if (size_stack(data->b_stack) >= 0)
		push_a(data);
	while (data->a_stack->order != 0)
		ra(data);
}
