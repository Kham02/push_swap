/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:42 by estrong           #+#    #+#             */
/*   Updated: 2022/03/12 23:51:31 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_bub(t_data *data)
{
	int	i;

	i = 0;
	while (i <= size_stack(data->a_stack))
	{
		if (data->a_stack->val > data->a_stack->next->val)
			sa(data);
		else
			ra(data);
		i++;
	}
}

int	size_stack(t_listp *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst->next;
		count++;
	}
	return (count);
}

void	lstnew(t_listp *lst)
{
	
}