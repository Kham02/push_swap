/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:49 by estrong           #+#    #+#             */
/*   Updated: 2022/03/25 18:01:41 by estrong          ###   ########.fr       */
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
	if (!ft_isdigit(str[i]))
			error(data);
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
	t_listp	*lst;

	data->i = 0;
	lst = data->a_stack;
	data->size_a = size_stack(data->a_stack);
	while (data->i < data->size_a)
	{
		if (lst->val > lst->next->val)
			return(1);
		lst = lst->next;
		data->i++;
	}
	return(0);
}

void	search_max(t_data *data, t_listp *lst)
{
	t_listp	*lst1;
	int		size;

	lst1 = lst;
	data->i = 0;
	data->max = 0;
	size = size_stack(data->a_stack);
	data->max = lst1->val;
	while (data->i <= size)
	{
		if (data->max < lst1->val)
			data->max = lst1->val;
		data->i++;
		lst1 = lst1->next;
	}
}

void	search_min(t_data *data, t_listp *lst)
{
	t_listp	*lst1;
	int		size;

	lst1 = lst;
	data->i = 0;
	size = size_stack(data->a_stack);
	
	data->min = data->max;
	while (data->i <= size)
	{
		if (data->min > lst1->val && lst1->order == -1)
			data->min = lst1->val;
		data->i++;
		lst1 = lst1->next;
	}
}

void	order(t_data *data)
{
	t_listp	*lst;
	int		i;
	int		j;
	int		size;

	size = size_stack(data->a_stack);
	i = 0;
	while (i <= size)
	{
		lst = data->a_stack;
		j = 0;
		search_max(data, lst);
		search_min(data, lst);
		while (j <= size)
		{
			if (data->min == lst->val)
			{
				lst->order = data->order;
				data->order++;
			}
			j++;
			lst = lst->next;
		}
		i++;
	}
}
