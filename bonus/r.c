/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:20 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 20:07:13 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_data *data)
{
	t_listp	*list;
	if (size_stack(data->a_stack) >= 1)
	{
		list = lst_last(data->a_stack);
		list->next = data->a_stack;
		data->a_stack = data->a_stack->next;
		list->next->next = NULL;
		ft_putstr_fd("ra\n", 1);
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
		ft_putstr_fd("rb\n", 1);
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
		ft_putstr_fd("rr\n", 1);
	}
}