/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:16 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 21:13:04 by estrong          ###   ########.fr       */
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

int	check_dub(char **av)
{
	int	i;
	int	n;

	i = 0;
	while (av[i])
	{
		n = 0;
		while (av[n] && i != n)
		{
			if (!ft_strcmp(av[i], av[n]))
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}
