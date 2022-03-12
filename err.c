/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:59:03 by estrong           #+#    #+#             */
/*   Updated: 2022/03/12 23:49:06 by estrong          ###   ########.fr       */
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
	free_list(data->a_stack);
	free_list(data->b_stack);
	free_list(data->stack);
	exit(1);
}

// void	free_all(t_data *data)
// {
	
// }

// void	free_list(t_listp *list)
// {
// 	while (list->next)
// 	{
// 		free(list);
// 		list = list->next;
// 	}
// }

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
