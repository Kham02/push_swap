/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:59:03 by estrong           #+#    #+#             */
/*   Updated: 2022/04/04 13:04:23 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	error(t_data *data)
{
	if (data->a_stack)
		free_list(data->a_stack);
	write(1, "Error\n", 6);
	data = NULL;
	exit(EXIT_FAILURE);
}

void	end(t_data *data)
{
	if (data->a_stack)
		free_list(data->a_stack);
	data = NULL;
	exit(1);
}

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
