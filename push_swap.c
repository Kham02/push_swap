/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:12 by estrong           #+#    #+#             */
/*   Updated: 2022/03/23 17:47:36 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	values(t_data *data)
{
	data->stack = NULL;
	data->a_stack = NULL;
	data->b_stack = NULL;
	data->max = 0;
	data->mid = 0;
	data->next_order = 0;
}

void	check(t_data *data, char **av)
{
	int	i;

	i = 1;
	values(data);
	while (av[i])
	{
		lst_add_back(&data->a_stack, lst_new(push_swap_atoi(data, (char *)av[i], 0, 1)));
		i++;
	}
	if (check_sort(data) == 0 || size_stack(data->a_stack) <= 1)
		end(data);
	else
	{
		// write (1, "3\n", 2);
		bub(data);
		print(data->a_stack);
		if (size_stack(data->a_stack) <= 5)
			sort_min(data);
		else
			sort(data);
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
	check(data, av);
	return (0);
}