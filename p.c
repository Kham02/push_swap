/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:59:57 by estrong           #+#    #+#             */
/*   Updated: 2022/03/26 17:08:30 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//сверху б наверх а
void	pa(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->b_stack) >= 0)
	{
		list1 = data->b_stack;
		list2 = data->a_stack;
		data->b_stack = list1->next;
		data->a_stack = list1;
		list1->next = list2;
		ft_putstr_fd("pa\n", 1);
	}
}

//сверху а наверх б
void	pb(t_data *data)
{
	t_listp	*list1;
	t_listp	*list2;

	if (size_stack(data->a_stack) >= 0)
	{
		list1 = data->a_stack;
		list2 = data->b_stack;
		data->a_stack = list1->next;
		data->b_stack = list1;
		list1->next = list2;
		ft_putstr_fd("pb\n", 1);
	}
}
