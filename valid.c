/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:49 by estrong           #+#    #+#             */
/*   Updated: 2022/03/23 19:52:31 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_atoi(t_data *data, char *str, unsigned int n, int s)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		s = -1;
	}
	if (str[i] == '+' && s == 1)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
	}
	return(n * s);
}

int	check_sort(t_data *data)
{
	data->i = 0;
	data->size_a = size_stack(data->a_stack);
	while (data->i < data->size_a)
	{
		if (data->a_stack->val > data->a_stack->next->val)
			return(1);
		data->a_stack = data->a_stack->next;
		data->i++;
	}
	return(0);
}

void	search_min(t_data *data)
{
	t_listp	*lst;
	int		size;

	lst = data->a_stack;
	data->i = 0;
	data->min = 0;
	size = size_stack(data->a_stack);
	data->min = lst->val;
	while (data->i <= size)
	{
		data->j = 0;
		while (data->j <= size)
		{
			if (data->min > lst->val && lst->order == -1)
				data->min = lst->val;
			data->j++;
		}
		data->i++;
	}
}

void	order(t_data *data)
{
	int	i;
	int	j;
	int	size;

	size = size_stack(data->a_stack);
	i = 0;
	while (i <= size)
	{
		j = 0;
		search_min(data);
		while (j <= size)
		{
			if (data->min == data->a_stack->val)
			{
				data->a_stack->order = data->order;
				data->order++;
			}
			j++;
		}
		i++;
	}
}
