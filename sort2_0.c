/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:55:44 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 23:01:23 by estrong          ###   ########.fr       */
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
	init_cost(data);
}
