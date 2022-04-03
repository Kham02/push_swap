/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:49 by estrong           #+#    #+#             */
/*   Updated: 2022/04/03 18:20:06 by estrong          ###   ########.fr       */
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
	check_int(data, str);
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
	}
	return (n * s);
}

void	check_int(t_data *data, char *str)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error(data);
		i++;
	}
}

int	check_sort(t_data *data)
{
	t_listp	*lst;
	int		i;

	lst = data->a_stack;
	i = size_stack(lst);
	while (lst->next != NULL && i >= 0)
	{
		if (lst->order > lst->next->order)
			return (1);
		i--;
		lst = lst->next;
	}
	return (0);
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
