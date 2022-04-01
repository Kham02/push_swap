/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:20 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 17:54:03 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_data *data)
{
	t_listp	*list;

	if (size_stack(data->a_stack) >= 1)
	{
		list = lst_last(data->a_stack);
		list->next = data->a_stack;
		data->a_stack = data->a_stack->next;
		list->next->next = NULL;
	}
}

void	rb(t_data *data)
{
	t_listp	*list;

	if (size_stack(data->b_stack) >= 1)
	{
		list = lst_last(data->b_stack);
		list->next = data->b_stack;
		data->b_stack = data->b_stack->next;
		list->next->next = NULL;
	}
}

void	rr(t_data *data)
{
	t_listp	*list;

	if (size_stack(data->a_stack) >= 1 && size_stack(data->b_stack) >= 1)
	{
		list = lst_last(data->a_stack);
		list->next = data->a_stack;
		data->a_stack = data->a_stack->next;
		list->next->next = NULL;
		list = lst_last(data->b_stack);
		list->next = data->b_stack;
		data->b_stack = data->b_stack->next;
		list->next->next = NULL;
	}
}
