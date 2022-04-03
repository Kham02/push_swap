/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:55:41 by estrong           #+#    #+#             */
/*   Updated: 2022/04/03 18:05:22 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_data *data, t_listp *lst_b)
{
	t_listp	*lst_a;
	int		mov;

	lst_b->cost_a = 0;
	mov = 0;
	lst_a = data->a_stack;
	while (lst_a->order != data->next_order)
	{
		lst_a = lst_a->next;
		mov++;
	}
	if (((size_stack(data->a_stack) + 1) - mov) < mov)
	{
		lst_b->cost_a = -1;
		mov = ((size_stack(data->a_stack) + 1) - mov);
	}
	return (mov);
}

void	search_next_ord(t_data *data, t_listp *lst_b)
{
	t_listp	*lst_a;

	data->next_order = 10000;
	lst_a = data->a_stack;
	while (lst_a)
	{
		if (lst_a->order > lst_b->order && data->next_order > lst_a->order)
			data->next_order = lst_a->order;
		lst_a = lst_a->next;
	}
}

void	init_cost(t_data *data)
{
	t_listp	*lst_b;
	int		cos_a;
	int		cos_b;
	int		i;

	i = 0;
	lst_b = data->b_stack;
	while (lst_b)
	{
		lst_b->flag = 0;
		search_next_ord(data, lst_b);
		cos_a = cost_a(data, lst_b);
		cos_b = i;
		if (cos_b > (size_stack(data->b_stack) + 1) - i)
		{
			lst_b->flag = 1;
			cos_b = (size_stack(data->b_stack) + 1) - i;
		}
		lst_b->cost = cos_a + cos_b;
		lst_b = lst_b->next;
		i++;
	}
}

t_listp	*search_min_mov(t_data *data)
{
	t_listp	*lst_b;
	t_listp	*lst_a;
	int		min_mov;

	lst_a = data->a_stack;
	lst_b = data->b_stack;
	min_mov = 1000;
	while (lst_b)
	{
		if (lst_b->cost < min_mov)
			min_mov = lst_b->cost;
		lst_b = lst_b->next;
	}
	lst_b = data->b_stack;
	while (lst_b)
	{
		if (lst_b->cost == min_mov)
		{
			search_next_ord(data, lst_b);
			return (lst_b);
		}
		lst_b = lst_b->next;
	}
	return (0);
}

void	order(t_data *data)
{
	t_listp	*lst;
	int		i;
	int		j;
	int		size;

	size = size_stack(data->a_stack);
	i = 0;
	while (i <= size)
	{
		lst = data->a_stack;
		j = 0;
		search_max(data, lst);
		search_min(data, lst);
		while (j <= size)
		{
			if (data->min == lst->val)
			{
				lst->order = data->order;
				data->order++;
			}
			j++;
			lst = lst->next;
		}
		i++;
	}
}
