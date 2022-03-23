/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:06:06 by estrong           #+#    #+#             */
/*   Updated: 2022/03/23 19:34:07 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_stack(t_listp *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_listp	*lst_new(int val)
{
	t_listp	*new_list;

	new_list = malloc(sizeof(t_listp));
	if (!new_list)
		return (NULL);
	new_list->val = val;
	new_list->order = 0;
	new_list->flag = 0;
	new_list->next = NULL;
	return (new_list);
}

void	lst_add_back(t_listp **lst, t_listp *new_lst)
{
	t_listp	*tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
	else
		*lst = new_lst;
}

t_listp	*lst_last(t_listp *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_listp	*copy_stack(t_listp *stack)
{
	t_listp	*stack2;
	int		size;

	stack2 = NULL;
	size = size_stack(stack);
	while (size > 0)
	{
		lst_add_back(stack2, stack);
		print(stack2);
		size--;
	}
	return (stack2);
}

void	copy_stack_in_arr(t_data *data, t_listp *lst)
{
	int	i;
	// int	c;

	// c = 0;
	print(lst);
	i = 0;
	while (lst)
	{
		data->arr[i] = lst->val;
		lst = lst->next;
		i++;
		// c = data->arr[i];
		// write(2, &lst->val, 1);
	}
}
