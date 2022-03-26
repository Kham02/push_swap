/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:42 by estrong           #+#    #+#             */
/*   Updated: 2022/03/26 12:34:20 by estrong          ###   ########.fr       */
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
	int	a;
	int	an;
	int	ann;

	a = data->a_stack->val;
	an = data->a_stack->next->val;
	ann = data->a_stack->next->next->val;
	if (a < an && a < ann && an > ann) //1 3 2
		sa(data);
	if (a > an && a > ann && an > ann) //3 2 1
		ra(data);
	if (a > an && a > ann && an < ann) //3 1 2
		ra(data);
	if (a > an && a < ann && an < ann) //2 1 3
		sa(data);
	if (a < an && a > ann && an > ann) //2 3 1
		rra(data);
	if (check_sort(data) != 0)
		sort_min(data);
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
		if (data->a_stack->order > 2)
			pb(data);
		else
			ra(data);
		size++;
		// debug_print(&data->a_stack, &data->b_stack);
	}
	sort_3_el(data);
	size = 0;
	pa(data);
	pa(data);
	if (data->a_stack->order == 4)
		sa(data);
	if (data->a_stack->order == 3)
		ra(data);
	ra(data);
	// print(data->a_stack);
}