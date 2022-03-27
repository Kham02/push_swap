/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:13 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 20:08:14 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	size_stack(t_listp *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (-1);
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
	new_list->order = -1;
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