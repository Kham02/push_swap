/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:12 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 20:52:19 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	values(t_data *data)
{
	data->max = 0;
	data->mid = 0;
	data->next_order = 0;
}

void	check(t_data *data, int ac, char *av)
{
	int	i;

	i = 0;
	values(data);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0 || av[i] != 32)
			error(data);
		lst_add_back(data->a_stack, lst_new(push_swap_atoi(av[i], 0, 1)));
		i++;
	}
	if (check_sort(data) == 0 || size_stack(data->a_stack) <= 1)
		end(data);
	else
	{
		bub(data);
		if (size_stack(data->a_stack) <= 5)
			sort_min(data);
		else
			qs(data);
	}
	end(data);
}

void	print(t_listp *list)
{
	t_listp	*p;

	p = list;
	printf("\033[38;05;32;48;05;232m""| num |\t|index|\t| flag |""\033[m""\n");
	while (p != NULL)
	{
		printf("\033[38;05;115m""  %d\t  %d\t  %d""\033[m""\n", \
		(int)p->val, (int)p->order, p->flag);
		p = p->next;
	}
}

int	main(int ac ,char **av)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		error(data);
	if (ac < 2)
		error(data);
	// if (!(data->a_stack = (t_listp *)malloc(sizeof(t_listp))))
	// 	error(data);
	check(data, ac, av[2]);
	return (0);
}