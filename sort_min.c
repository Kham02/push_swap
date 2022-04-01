/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:42 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 23:08:11 by estrong          ###   ########.fr       */
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
	int	a;
	int	an;
	int	ann;

	a = data->a_stack->order;
	an = data->a_stack->next->order;
	ann = data->a_stack->next->next->order;
	if (a < an && a < ann && an > ann)
		sa(data);
	if (a > an && a > ann && an > ann)
		ra(data);
	a = data->a_stack->order;
	an = data->a_stack->next->order;
	ann = data->a_stack->next->next->order;
	if (a > an && a > ann && an < ann)
		ra(data);
	if (a > an && a < ann && an < ann)
		sa(data);
	if (a < an && a > ann && an > ann)
		rra(data);
}

void	sort_4_el(t_data *data)
{
	int	size;

	size = 0;
	while (size <= 4)
	{
		if (data->a_stack->order < 2)
			pb(data);
		else
			ra(data);
		size++;
	}
	sort_2_el(data);
	size = 0;
	while (size <= 1)
	{
		if (data->b_stack->order == 1)
			pa(data);
		else
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
		if (data->a_stack->order < 2)
			pb(data);
		else
			ra(data);
		size++;
	}
	sort_3_el(data);
	pa(data);
	pa(data);
	if (data->a_stack->order == 1)
		sa(data);
}
