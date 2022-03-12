/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:20 by estrong           #+#    #+#             */
/*   Updated: 2022/03/12 17:33:27 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//сверху вниз
void	ra(t_data *data)
{
	t_listp	list;

	list = ft_lstlast(data->a_stack);
	list->next = data->a_stack;
	list->next->next = NULL;
	data->a_stack = data->a_stack->next;
	ft_lstlast(data->a_stack)->next = list->next;
	free_list(list);
	ft_putstr_fd("ra\n", 1);
}

//сверху вниз
void	rb(t_data *data)
{
	t_listp	list;

	list = ft_lstlast(data->b_stack);
	list->next = data->b_stack;
	list->next->next = NULL;
	data->b_stack = data->b_stack->next;
	ft_lstlast(data->b_stack)->next = list->next;
	free_list(list);
	ft_putstr_fd("rb\n", 1);
}

//ra rb
void	rr(t_data *data)
{
	t_listp	list;

	list = ft_lstlast(data->a_stack);
	list->next = data->a_stack;
	list->next->next = NULL;
	data->a_stack = data->a_stack->next;
	ft_lstlast(data->a_stack)->next = list->next;
	list = ft_lstlast(data->b_stack);
	list->next = data->b_stack;
	list->next->next = NULL;
	data->b_stack = data->b_stack->next;
	ft_lstlast(data->b_stack)->next = list->next;
	free_list(list);
	ft_putstr_fd("rr\n", 1);

}