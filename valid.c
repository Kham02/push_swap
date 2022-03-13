/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:49 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 21:05:11 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	null_null(t_data *data)
// {
// 	data->j = 0;
// 	data->i = 0;
// 	data->size_a = 0;
// 	data->size_b = 0;
// 	data->next_order = 1;
	// data->stack = NULL;
	// data->a_stack->val = 0;
	// data->a_stack->order = 0;
	// data->a_stack->flag = 0;
	// data->a_stack->next = NULL;
// }

void	check_valid(t_data *data)
{
	data->i = 0;
	while (data->str[data->i] || ft_isdigit(data->str[data->i]) || data->str[data->i] == 9 || 
		data->str[data->i] == 13 || data->str[data->i] == 32 || data->str[data->i] == ',' || 
		data->str[data->i] == '+' || data->str[data->i] == '-')
		data->i++;
	if (data->str[data->i] != '\0')
		error(data);
	// write(1, "lol\n", 4);
	write_stack(data);
}

void	write_stack(t_data *data)
{
	// null_null(data);
			// write(1, "lol\n", 4);
	printf("%s\n", data->str);
	while (data->str[data->i])
	{
		if (ft_isdigit(data->str[data->i]) || data->str[data->i] == '-' || data->str[data->i] == '+')
		{
			data->j = data->i;
			lst_add_back(data->a_stack, lst_new(push_swap_atoi(data, 0, 1)));
		}
		data->i++;
	}
	// print(data->a_stack);
	data->str = ft_strdup("");
}

int	push_swap_atoi(t_data *data, unsigned int n, int s)
{
	// printf("\n%d\n", data->str[data->j]);
	while ((data->str[data->j] > 8 && data->str[data->j] < 14) || data->str[data->j] == 32 || data->str[data->j] == ',')
		data->j++;
	if (data->str[data->j] == '-')
	{
		data->j++;
		s = -1;
	}
	if (data->str[data->j] == '+' && s == 1)
		data->j++;
	while (data->str[data->j] > 47 && data->str[data->j] < 58)
	{
		n = n * 10 + (data->str[data->j] - 48);
		data->j++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
		if (!ft_isdigit(data->str[data->i]) || data->str[data->i] != '-' || data->str[data->i] != '+')
			break ;
	}
	// ft_putnbr_fd(n * s, 1);
	return(n * s);
}

int	check_sort(t_data *data)
{
	data->i = 0;
	data->size_a = size_stack(data->a_stack);
	while (data->i < data->size_a)
	{
		if (data->a_stack->val > data->a_stack->next->val)
			return(1);
		// printf("%d\n", data->a_stack->val);
		data->a_stack = data->a_stack->next;
		data->i++;
	}
	return(0);
}
