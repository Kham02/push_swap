/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:55:41 by estrong           #+#    #+#             */
/*   Updated: 2022/03/30 15:53:02 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_data *data, t_listp *lst_b)
{
	t_listp	*lst_a;
	int		mov;
	int		p;

	mov = 0;
	data->a_rr = 0;
	lst_a = data->a_stack;
	p = cost_a_utils(lst_a, lst_b);
	lst_a = data->a_stack;
	lst_b->cost_a = 0;
	while (p != lst_a->order)
	{
		mov++;
		lst_a = lst_a->next;
	}
	if ((size_stack(data->a_stack) + 1) - mov < mov)
	{
		lst_b->cost_a = -1;
		mov = (size_stack(data->a_stack) + 1) - mov;
	}
	return (mov);
}

int	cost_a_utils(t_listp *lst_a, t_listp *lst_b)
{
	int	p;

	p = 1000;
	while (lst_a)
	{
		lst_a->flag = 0;
		if (lst_a->order > lst_b->order)
		{
			if (p > lst_a->order)
				p = lst_a->order;
		}
		lst_a = lst_a->next;
	}
	return (p);
}

void	init_cost(t_data *data)
{
	t_listp	*lst_b;
	int		cos_a;
	int		cos_b;
	int		i;

	i = 0;
	lst_b = data->b_stack;
	data->min_mov = data->b_stack;
	while (lst_b)
	{
		lst_b->flag = 0;
		cos_a = cost_a(data, lst_b);
		cos_b = i;
		if (cos_b > (size_stack(data->b_stack) + 2) - i)
		{
			lst_b->flag = 1;
			cos_b = (size_stack(data->b_stack) + 2) - i;
		}
		lst_b->cost = cos_a + cos_b;
		if (data->min_mov->cost >= lst_b->cost)
			data->min_mov = lst_b;
		lst_b = lst_b->next;
		i++;
	}
}

void	rr_scroll(t_data *data, t_listp *lst_mov)
{
	if (lst_mov->flag == 1 && lst_mov->cost_a == -1)
	{
		while (data->a_stack->order < data->next_order && data->b_stack != lst_mov)
			rrr(data);
	}
	if (lst_mov->cost_a == -1)
	{
		while (data->a_stack->order < data->next_order)
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
		while (data->a_stack->order < data->next_order && data->b_stack != lst_mov)
			rr(data);
	}
	if (lst_mov->cost_a == 0)
	{
		while (data->a_stack->order < data->next_order)
			ra(data);
	}
	if (lst_mov->flag == 0)
	{
		while (data->b_stack != lst_mov)
			rb(data);
	}
}