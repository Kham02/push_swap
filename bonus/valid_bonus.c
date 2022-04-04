/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:19:19 by estrong           #+#    #+#             */
/*   Updated: 2022/04/04 13:14:41 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	push_swap_atoi(t_data *data, char *str, unsigned int n, int s)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		s = -1;
	}
	if (str[i] == '+' && s == 1)
		i++;
	check_int(data, str);
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
	}
	return (n * s);
}

void	check_int(t_data *data, char *str)
{
	int	i;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error(data);
		i++;
	}
}

void	check_valid(t_data *data, char **av)
{
	int	i;

	i = 1;
	data->a_stack = NULL;
	data->b_stack = NULL;
	while (av[i])
	{
		lst_add_back(&data->a_stack, \
		lst_new(push_swap_atoi(data, (char *)av[i], 0, 1)));
		i++;
	}
	check_dub(data);
}
