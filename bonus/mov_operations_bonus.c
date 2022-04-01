/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_operations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:03 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 21:13:20 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_op(t_data *data, char *str)
{
	if (!ft_strcmp("ra\n", str))
		ra(data);
	else if (!ft_strcmp("rra\n", str))
		rra(data);
	else if (!ft_strcmp("rr\n", str))
		rr(data);
	else if (!ft_strcmp("rrr\n", str))
		rrr(data);
	else if (!ft_strcmp("sa\n", str))
		sa(data);
	else if (!ft_strcmp("pa\n", str))
		pa(data);
	else if (!ft_strcmp("pb\n", str))
		pb(data);
	else if (!ft_strcmp("rb\n", str))
		rb(data);
	else if (!ft_strcmp("rrb\n", str))
		rrb(data);
	else if (!ft_strcmp("ss\n", str))
		ss(data);
	else if (!ft_strcmp("sb\n", str))
		sb(data);
	else
		error(data);
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
