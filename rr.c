/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:27 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 17:42:44 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->a_stack) >= 1)
	{
		list1 = data->a_stack;
		while (list1->next->next)
			list1 = list1->next;
		list2 = list1->next;
		list1->next = NULL;
		list2->next = data->a_stack;
		data->a_stack = list2;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->b_stack) >= 1)
	{
		list1 = data->b_stack;
		while (list1->next->next)
			list1 = list1->next;
		list2 = list1->next;
		list1->next = NULL;
		list2->next = data->b_stack;
		data->b_stack = list2;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->b_stack) >= 1 && size_stack(data->a_stack) >= 1)
	{
		list1 = data->a_stack;
		while (list1->next->next)
			list1 = list1->next;
		list2 = list1->next;
		list1->next = NULL;
		list2->next = data->a_stack;
		data->a_stack = list2;
		list1 = data->b_stack;
		while (list1->next->next)
			list1 = list1->next;
		list2 = list1->next;
		list1->next = NULL;
		list2->next = data->b_stack;
		data->b_stack = list2;
		ft_putstr_fd("rrr\n", 1);
	}
}
