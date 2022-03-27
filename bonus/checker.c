/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:18:06 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 20:41:39 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_list(t_listp *list)
{
	t_listp	*fr;
	t_listp	*r;

	if (list)
	{
		r = list;
		while (r->next)
		{
			fr = r->next;
			free(r);
			r = fr;
		}
		list = NULL;
	}
}

void	error(t_data *data)
{
	write(1, "Error\n", 6);
	if (data->a_stack)
		free_list(data->a_stack);
	if (data->b_stack)
		free_list(data->b_stack);
	data = NULL;
	exit(EXIT_FAILURE);
}

void	end(t_data *data)
{
	if (check_sort(data) == 0 && size_stack(data->b_stack) < 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (data->a_stack)
		free_list(data->a_stack);
	if (data->b_stack)
		free_list(data->b_stack);
	data = NULL;
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data *));
	if (!data)
		error(data);
	if (ac < 2)
		error(data);
	check_valid(data, av);
	reed_op(data);
	end(data);
	return (0);
}