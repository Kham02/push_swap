/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:59:03 by estrong           #+#    #+#             */
/*   Updated: 2022/03/24 23:50:09 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	error(t_data *data)
{
	free_list(data->a_stack);
	data = NULL;
	write(1, "Error\n", 6);
	exit(0);
	return(0);
}

void	end(t_data *data)
{
	free_list(data->a_stack);
	data = NULL;
	exit(1);
}

void	free_list(t_listp *list)
{
	t_listp	*fr;
	t_listp	*r;

	r = list;
	while (list->next)
	{
		fr = r->next;
		free(r);
		r = fr;
	}
	list = NULL;
}
