/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:30 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 20:28:18 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->a_stack) >= 1)
	{
		list1 = data->a_stack;
		list2 = data->a_stack->next;
		data->a_stack = list2;
		list1->next = list2->next;
		list2->next = list1;
	}
}

void	sb(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->b_stack) >= 1)
	{
		list1 = data->b_stack;
		list2 = data->b_stack->next;
		data->b_stack = list2;
		list1->next = list2->next;
		list2->next = list1;
	}
}

void	ss(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->a_stack) >= 1 && size_stack(data->b_stack) >= 1)
	{
		list1 = data->a_stack;
		list2 = data->a_stack->next;
		data->a_stack = list2;
		list1->next = list2->next;
		list2->next = list1;
		list1 = data->b_stack;
		list2 = data->b_stack->next;
		data->b_stack = list2;
		list1->next = list2->next;
		list2->next = list1;
	}
}
