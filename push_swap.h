/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:16 by estrong           #+#    #+#             */
/*   Updated: 2022/03/13 19:58:58 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_listp
{
	int				val;
	int				order;
	int				flag;
	struct s_listp	*next;
}t_listp;

typedef struct s_data
{
	t_listp	*a_stack;
	t_listp	*b_stack;
	t_listp	*stack;
	char	*str;
	char	*str2;
	int		*str_int;
	int		size_a;
	int		size_b;
	int		i;
	int		j;
	int		min;
	int		max;
	int		mid;
	int		f;
	int		next_order;
	int		val_bub;
	int		count;
}t_data;

void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

int		size_stack(t_listp *lst);
t_listp	*lst_new(int val);
t_listp	*lst_last(t_listp *lst);
void	lst_add_back(t_listp *lst, t_listp *new_lst);
void	check(t_data *data, int ac, char **av);
void	values(t_data *data);
void	check_valid(t_data *data);
void	write_stack(t_data *data);
int		push_swap_atoi(t_data *data, unsigned int n, int s);
char	error(t_data *data);
// void	free2arr(char **str);
int		check_sort(t_data *data);
void	qs(t_data *data);
void	recursion_b(t_data *data);
void	sort_b(t_data *data);
void	sort_a(t_data *data);
void	sort_stack_bub(t_data *data);
void	insertion_sort(t_data *data);
void	bub(t_data *data);
void	search_mid(t_data *data);
// int		check_size_stack(t_listp *stack);
void	free_list(t_listp *list);
void	end(t_data *data);

// DEBUG ###################
void	print(t_listp *list);


#endif