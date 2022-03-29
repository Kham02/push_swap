/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:12 by estrong           #+#    #+#             */
/*   Updated: 2022/03/29 15:16:00 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	values(t_data *data)
{
	// data->stack = NULL;
	data->a_stack = NULL;
	data->b_stack = NULL;
	data->min = 0;
	data->mid = 0;
	data->next_order = 0;
	data->order = 0;
	data->fl = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

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

void	check(t_data *data, char **av)
{
	int	i;

	i = 1;
	values(data);
	if (check_dub(av) != 1)
		error(data);
	while (av[i])
	{
		lst_add_back(&data->a_stack, lst_new(push_swap_atoi(data, (char *)av[i], 0, 1)));
		i++;
	}
}

void	print(t_listp *list)
{
	t_listp	*p;

	p = list;
	printf("\033[38;05;32;48;05;232m""| num |\t|index|\t| cost |""\033[m""\n");
	while (p != NULL)
	{
		printf("\033[38;05;115m""  %d\t  %d\t  %d""\033[m""\n", \
		(int)p->val, (int)p->order, p->cost);
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
	if (check_sort(data) == 0 || size_stack(data->a_stack) <= 0)
		end(data);
	order(data);
	if (size_stack(data->a_stack) < 5)
		sort_min(data);
	else
	{
		push_b(data);
		sort_3_el(data);
		push_a(data);
		// print(data->a_stack);
		// print(data->b_stack);
	}
	end(data);
	return (0);
}

// void	debug_print(t_listp **stack_a, t_listp **stack_b)
// {
// 	getchar();
// 	system("clear");
// 	printf("\033[04;38;05;76;48;05;232m"\
// 	"stack_a:                       \n""\033[m");
// 	print(*stack_a);
// 	printf("\033[38;05;124;48;05;232m"\
// 	"stack_b:                       \n""\033[m");
// 	print(*stack_b);
// 	write(1, "\033[38;05;226m", 13);
// }