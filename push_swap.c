/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:12 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 21:12:16 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	values(t_data *data)
{
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

void	check(t_data *data, char **av)
{
	int	i;

	i = 1;
	values(data);
	if (check_dub(av) != 1)
		error(data);
	while (av[i])
	{
		lst_add_back(&data->a_stack, \
		lst_new(push_swap_atoi(data, (char *)av[i], 0, 1)));
		i++;
	}
	order(data);
	if (check_sort(data) == 0 || size_stack(data->a_stack) <= 0)
		end(data);
	if (size_stack(data->a_stack) < 5)
		sort_min(data);
	else
	{
		push_b(data);
		sort_3_el(data);
		push_a(data);
	}
	end(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error(data);
	if (ac < 2)
	{
		write(1, "Error\n", 6);
		data = NULL;
		exit(EXIT_FAILURE);
		return (0);
	}
	check(data, av);
	return (0);
}
