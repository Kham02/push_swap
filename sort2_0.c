/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:55:44 by estrong           #+#    #+#             */
/*   Updated: 2022/03/31 16:09:11 by estrong          ###   ########.fr       */
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
	lst_mov = search_min_mov(data);
	// printf("next_order: %d\n", data->next_order);
	if (lst_mov->flag == 1 || lst_mov->cost_a == -1)
		rr_scroll(data, lst_mov);
	else
		r_scroll(data, lst_mov);
	if (data->a_stack->order == data->next_order && data->b_stack == lst_mov)
		pa(data);
	if (size_stack(data->b_stack) >= 0)
		push_a(data);
	scroll(data);
	// print(data->a_stack);
	// print(data->b_stack);
}

void	scroll(t_data *data)
{
	t_listp	*lst_a;
	int		i;

	i = 0;
	lst_a = data->a_stack;
	while (lst_a->order != 0)
	{
		lst_a = lst_a->next;
		i++;
	}
	if (i > (size_stack(data->a_stack) + 1) - i)
	{
		while (data->a_stack->order != 0)
			rra(data);
	}
	else
	{
		while (data->a_stack->order != 0)
			ra(data);
	}
}

void	rr_scroll(t_data *data, t_listp *lst_mov)
{
	if (lst_mov->flag == 1 && lst_mov->cost_a == -1)
	{
		while (data->a_stack->order != data->next_order && data->b_stack != lst_mov)
			rrr(data);
	}
	if (lst_mov->cost_a == -1)
	{
		while (data->a_stack->order != data->next_order)
			rra(data);
	}
	if (lst_mov->flag == 1)
	while (data->b_stack != lst_mov)
		rrb(data);
}

void	r_scroll(t_data *data, t_listp *lst_mov)
{
	if (lst_mov->flag == 0 && lst_mov->cost_a == 0)
	{
		while (data->a_stack->order != data->next_order && data->b_stack != lst_mov)
			rr(data);
	}
	if (lst_mov->cost_a == 0)
	{
		while (data->a_stack->order != data->next_order)
			ra(data);
	}
	if (lst_mov->flag == 0)
	{
		while (data->b_stack != lst_mov)
			rb(data);
	}
}