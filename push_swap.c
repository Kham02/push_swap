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
	data->i = 1;
	data->str = ft_strdup("");
	data->min = 0;
	data->mid = 0;
	data->max = 0;
	data->next_order = 0;
	// data->a_stack->next = NULL;
}

void	check(t_data *data, int ac, char **av)
{
	values(data);
	while (data->i <= ac - 1)
	{
		data->str = ft_strjoin(data->str, av[data->i]);
		data->i++;
	}
	check_valid(data);
	if (check_sort(data) == 0 || size_stack(data->a_stack) <= 1)
		end(data);
	else
	{
		// bub(data);
		// if (size_stack(data->a_stack) <= 5)
		// {
		// 	sort_stack_bub(data);
		// }
		// else
		// qs(data);
	}
	// write(1, "r\n", 2);
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
	// 	error(data);x
	check(data, ac, av);
	return (0);
}