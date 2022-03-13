/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:59:03 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 17:42:20 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	error(t_data *data)
{
	free_list(data->a_stack);
	free_list(data->b_stack);
	free_list(data->stack);
	write(1, "Error\n", 6);
	exit(0);
	return(0);
}

void	end(t_data *data)
{
	data = NULL;
// 	free_list(data->a_stack);
// 	free_list(data->b_stack);
// 	free_list(data->stack);
	exit(1);
}

// void	free_all(t_data *data)
// {
	
// }

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
}

// void	free2arr(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		str[i] = NULL;
// 		i++;
// 	}
// 	free(str[i]);
// }
