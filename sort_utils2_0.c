/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:55:41 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 23:05:58 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_data *data, t_listp *lst_b)
{
	t_listp	*lst_a;
	int		i;
	int		mov;

	i = 0;
	lst_a = data->a_stack;
	while (lst_a->order < lst_b->order)
	{
		lst_a = lst_a->next;
		i++;;
	}
	mov = i;
	if (mov > (size_stack(data->a_stack) + 1) - i)
		mov = (size_stack(data->a_stack) + 1) - i;
	return (mov);
}

void	init_cost(t_data *data)
{
	t_listp	*lst_b;
	int		cos_a;
	int		cos_b;
	int		i;

	i = 0;
	data->min_mov = 10000;
	lst_b = data->b_stack;
	while (lst_b)
	{
		cos_a = cost_a(data, lst_b);
		cos_b = i;
		if (cos_b > (size_stack(lst_b) + 1) - i)
			cos_b = (size_stack(lst_b) + 1) - i;
		lst_b->cost = cos_a + cos_b;
		if (data->min_mov >= lst_b->cost)
		{
			data->min_mov = lst_b->cost;
			
		}
		lst_b = lst_b->next;
	}
}

