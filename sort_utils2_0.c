/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:55:41 by estrong           #+#    #+#             */
/*   Updated: 2022/03/29 16:54:58 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_data *data, t_listp *lst_b)
{
	t_listp	*lst_a;
	t_listp	*lst_ord;
	int		mov;
	int		cos_b;

	mov = 0;
	lst_a = data->a_stack;
	lst_ord->cost = size_stack(data->a_stack) + 1;
	while (lst_a)
	{
		if (lst_ord->order > lst_a->order && lst_a->order > lst_b->order)
			lst_ord = lst_a;
		lst_a = lst_a->next;
	}
	lst_a = data->a_stack;
	while (lst_ord != lst_a)
		mov++;
	mov += 1;
	if ((size_stack(lst_a) + 2) - mov < mov)
		mov = (size_stack(lst_a) + 2) - mov;
	return (mov);
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
		cos_a = cost_a(data, lst_b);
		printf("a%d\n", cos_a);
		cos_b = i;
		printf("bi%d\n", cos_b);
		if (cos_b > (size_stack(lst_b) + 2) - i)
			cos_b = (size_stack(lst_b) + 2) - i;
		printf("b%d\n", cos_b);
		lst_b->cost = cos_a + cos_b;
		if (data->min_mov->cost >= lst_b->cost)
			data->min_mov = lst_b;
		lst_b = lst_b->next;
		i++;
		print(data->a_stack);
		print(data->b_stack);
	}
}

void	rr_scroll(t_data *data, t_listp *lst_mov)
{
	while (data->a_stack->order < data->next_order && data->b_stack != lst_mov)
		rrr(data);
	while (data->a_stack->order < data->next_order)
		rra(data);
	while (data->b_stack != lst_mov)
		rrb(data);
}

void	r_scroll(t_data *data, t_listp *lst_mov)
{
	while (data->a_stack->order < data->next_order && data->b_stack != lst_mov)
		rr(data);
	while (data->a_stack->order < data->next_order)
		ra(data);
	while (data->b_stack != lst_mov)
		rb(data);
}