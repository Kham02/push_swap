/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:42 by estrong           #+#    #+#             */
/*   Updated: 2022/03/24 23:37:27 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min(t_data *data)
{
	data->size_a = size_stack(data->a_stack);
	if (data->size_a == 4)
		sort_5_el(data);
	if (data->size_a == 3)
		sort_4_el(data);
	if (data->size_a == 2)
		sort_3_el(data);
	if (data->size_a == 1)
		sort_2_el(data);
	if (check_sort(data) != 0)
		sort_min(data);
}

void	sort_2_el(t_data *data)
{
	t_listp	*lst;

	lst = data->a_stack->next;
	if (data->a_stack->val > lst->val)
		sa(data);
}

void	sort_3_el(t_data *data)
{
	int	size;

	size = 0;
	while (size <= 2)
	{
		if (data->a_stack->order == 2)
			pb(data);
		ra(data);
		size++;
	}
	sort_2_el(data);
	
	if (data->b_stack->order == 2)
	{
		pa(data);
		ra(data);
	}
}

void	sort_4_el(t_data *data)
{
	int	size;

	size = 0;
	while (size <= 4)
	{
		if (data->a_stack->order < 2)
			pb(data);
		ra(data);
		size++;
	}
	sort_2_el(data);
	size = 0;
	while (size <= 1)
	{
		if (data->b_stack->order == 1)
			pa(data);
		sb(data);
		size++;
	}
	pa(data);
}

void	sort_5_el(t_data *data)
{
	int	size;

	size = 0;
	while (size <= 5)
	{
		if (data->a_stack->order < 3)
			pb(data);
		ra(data);
		size++;
	}
	sort_2_el(data);
	size = 0;
	while (size <=3)
	{
		if (data->b_stack->order == 2)
			pa(data);
		rb(data);
		size++;
	}
	if (data->b_stack->order == 1)
		pa(data);
	else
	{
		sb(data);
		pa(data);
	}
	pa(data);
}