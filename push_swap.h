/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:16 by estrong           #+#    #+#             */
/*   Updated: 2022/03/12 15:42:55 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../Libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_list
{
	int				val;
	int				order;
	int				flag;
	struct s_list	*next;
}t_list;

typedef struct s_data
{
	t_list	a_stack;
	t_list	b_stack;
	t_list	stack;
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

int		main(int ac ,char **av);
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
int		check_size_stack(t_list *stack);
void	free_list(t_list *list);
void	end(t_data *data);
#endif