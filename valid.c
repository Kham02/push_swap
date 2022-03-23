/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:49 by estrong           #+#    #+#             */
/*   Updated: 2022/03/23 19:52:31 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
	}
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
		data->a_stack = data->a_stack->next;
		data->i++;
	}
	return(0);
}

void	bub(t_data *data) 
{
	t_listp	*lst;
	int		size;

	lst = copy_stack(data->a_stack);
	size = size_stack(data->stack);
	data->i = 0;
	while (data->i < size)
	{
		if (data->stack->val > data->stack->next->val)
		{
			data->val_bub = data->stack->val;
			data->stack->val = data->stack->next->val;
			data->stack->next->val = data->val_bub;
			if (data->stack->val == data->stack->next->val)
				error(data);
		}
		data->i++;
	}
	order(data);
}

// void	bub(t_data *data) 
// {
// 	t_listp	*stack;
// 	int		size;

// 	stack = data->a_stack;
// 	size = size_stack(stack);
// 	data->i = 0;
// 	while (data->i < size)
// 	{
// 		data->j = 0;
// 		while (data->j < size)
// 		{
// 			if (stack->val > stack->next->val)
// 			{
// 				data->val_bub = stack->val;
// 				stack->val = stack->next->val;
// 				stack->next->val = data->val_bub;
// 				if (stack->val == stack->next->val)
// 					error(data);
// 			}
// 			data->j++;
// 		}
// 		data->i++;
// 	}
// 	// print(data->stack);
// 	data->stack = stack;
// 	order(data);
// }

// void	bub(t_data *data)
// {
// 	int		size;
// 	int		i;
// 	int		j;
// 	int		c;

// 	i = 0;
// 	size = size_stack(data->a_stack);
// 	copy_stack_in_arr(data, data->a_stack);
// 	while (i <= size)
// 	{
// 		j = 0;
// 		while (j <= size)
// 		{
// 			if (data->arr[i] > data->arr[i + 1])
// 			{
// 				c = data->arr[i];
// 				data->arr[i] = data->arr[i + 1];
// 				data->arr[i + 1] = c;
// 			}
// 			// write(1, &data->arr[j], 1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	order(data);
// 	// print(data->a_stack);
// }

// void	order(t_data *data)
// {
// 	t_listp	*lst;
// 	int	i;
// 	int	j;
// 	int	size;

// 	i = 0;
// 	j = 0;
// 	lst = data->a_stack;
// 	size = size_stack(data->a_stack);
// 	while (i <= size)
// 	{
// 		j = 0;
// 		while (j <= size)
// 		{
// 			// print(data->a_stack);
// 			if (data->a_stack->val == data->arr[j])
// 				data->a_stack->order = j + 1;
// 			j++;
// 			data->a_stack = data->a_stack->next;
// 		}
// 		i++;
// 	}
// 	data->a_stack = lst;
// }

void	order(t_data *data)
{
	t_listp	*stack2;

	stack2 = copy_stack(data->a_stack);
	print(stack2);
	data->i = 0;
	data->size_a = size_stack(data->a_stack);
	while (data->i < data->size_a)
	{
		data->j = 0;
		while (data->j < data->size_a)
		{
			if (stack2->val == data->stack->val)
			{
				data->stack = data->stack->next;
				stack2->order = data->j + 1;
				stack2 = stack2->next;
			}
			data->j++;
			// write (1, "3\n", 2);
		}
		stack2 = stack2->next;
		data->i++;
	}
}
