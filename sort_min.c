/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:42 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 17:06:23 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	if (data->size_a == 5)
		sort_5_el(data);
	if (data->size_a == 4)
		sort_4_el(data);
	if (data->size_a == 3)
		sort_3_el(data);
	if (data->size_a == 2)
		sort_2_el(data);
	if (check_sort(data) != 0)
		sort_min(data);
}

void	sort_2_el(t_data *data)
{
	if (data->a_stack->val > data->a_stack->val->next)
		sa(data);
}

void	sort_3_el(t_data *data)
{
	while (data->a_stack)
	{
		if (data->a_stack->order != 2)
			pb(data);
		ra(data);
	}
	sort_2_el(data);
	if (data->b_stack->order == 1)
		pa(data);
	else
	{
		pa(data);
		ra(data);
	}
}

void	sort_4_el(t_data *data)
{
	while (data->a_stack)
	{
		if (data->a_stack->order < 3)
			pb(data);
		ra(data);
	}
	sort_2_el(data);
	while (data->b_stack)
	{
		if (data->b_stack->order == 2)
			pa(data);
		rb(data);
	}
	pb(data);
}

void	sort_5_el(t_data *data)
{
	while (data->a_stack)
	{
		if (data->a_stack->order < 4)
			pb(data);
		ra(data);
	}
	sort_2_el(data);
	while (data->b_stack)
	{
		if (data->b_stack->order == 3)
			pa(data);
		rb(data);
	}
	if (data->b_stack->order == 2)
		pb(data);
	else
	{
		sb(data);
		pb(data);
		pb(data);
	}
}