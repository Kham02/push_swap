/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:03 by estrong           #+#    #+#             */
/*   Updated: 2022/03/31 18:45:09 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_op(t_data *data, char *str)
{
	if (ft_strcmp(str, "pa\n"))
		pb(data);
	else if (ft_strcmp(str, "pb\n"))
		pb(data);
	else if (ft_strcmp(str, "ra\n"))
		ra(data);
	else if (ft_strcmp(str, "rb\n"))
		rb(data);
	else if (ft_strcmp(str, "rr\n"))
		rr(data);
	else if (ft_strcmp(str, "sa\n"))
		sa(data);
	else if (ft_strcmp(str, "sb\n"))
		sb(data);
	else if (ft_strcmp(str, "ss\n"))
		ss(data);
	else if (ft_strcmp(str, "rra\n"))
		rra(data);
	else if (ft_strcmp(str, "rrb\n"))
		rrb(data);
	// else
	// 	error(data);
}

void	reed_op(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		check_op(data, str);
		free(str);
		str = get_next_line(0);
	}
}