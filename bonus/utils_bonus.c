/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:16 by estrong           #+#    #+#             */
/*   Updated: 2022/04/04 13:13:04 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_sort(t_data *data)
{
	t_listp	*lst;
	t_listp	*lst1;
	int		i;

	lst = data->a_stack;
	lst1 = data->a_stack->next;
	i = size_stack(lst);
	while (lst->next != NULL && i >= 0)
	{
		if (lst->val > lst->next->val)
			return (1);
		i--;
		lst = lst->next;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	check_dub(t_data *data)
{
	t_listp	*lst_a;
	t_listp	*lst_a2;

	lst_a = data->a_stack;
	while (lst_a)
	{
		lst_a2 = data->a_stack;
		while (lst_a2)
		{
			if (lst_a != lst_a2)
			{
				if (lst_a->val - lst_a2->val == 0)
					error(data);
			}
			lst_a2 = lst_a2->next;
		}
		lst_a = lst_a->next;
	}
}
