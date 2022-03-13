/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:42 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 17:06:23 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_bub(t_data *data)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < size_stack(data->a_stack))
	{
		if (data->a_stack->val > data->a_stack->next->val)
			sa(data);
		else
			ra(data);
		n = data->a_stack->val;
		printf("%d\n\n", n);
		data->a_stack = data->a_stack->next;
		i++;
	}
	// write (1, "sbub\n", 5);
	// i = check_sort(data);
	// printf("%d\n", i);
	if (check_sort(data) != 0)
		sort_stack_bub(data);
	// write (1, "su\n", 3);
}
