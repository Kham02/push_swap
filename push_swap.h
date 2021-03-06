/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:00:16 by estrong           #+#    #+#             */
/*   Updated: 2022/04/03 18:09:53 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_listp
{
	int				val;
	int				order;
	int				flag;
	int				cost_a;
	int				cost;
	struct s_listp	*next;
}t_listp;

typedef struct s_data
{
	t_listp	*a_stack;
	t_listp	*b_stack;
	t_listp	*min_mov;
	int		size_a;
	int		size_b;
	int		*arr;
	int		i;
	int		j;
	int		max;
	int		min;
	int		mid;
	int		order;
	int		fl;
	int		val_bub;
	int		next_order;
	int		count;
	int		a_rr;
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
t_listp	*copy_stack(t_listp *stack);
void	lst_add_back(t_listp **lst, t_listp *new_lst);
void	check(t_data *data, char **av);
int		ft_strcmp(char *s1, char *s2);
void	check_dub(t_data *data);
void	values(t_data *data);
int		push_swap_atoi(t_data *data, char *str, unsigned int n, int s);
void	check_int(t_data *data, char *str);
void	order(t_data *data);
void	search_min(t_data *data, t_listp *lst);
void	search_max(t_data *data, t_listp *lst);
int		check_sort(t_data *data);
void	sort_min(t_data *data);
void	sort_2_el(t_data *data);
void	sort_3_el(t_data *data);
void	sort_4_el(t_data *data);
void	sort_5_el(t_data *data);
void	push_b(t_data *data);
void	push_a(t_data *data);
int		cost_a(t_data *data, t_listp *lst_b);
void	init_cost(t_data *data);
void	rr_scroll(t_data *data, t_listp *lst_mov);
void	r_scroll(t_data *data, t_listp *lst_mov);
void	search_next_ord(t_data *data, t_listp *lst_b);
t_listp	*search_min_mov(t_data *data);
void	scroll(t_data *data);
void	free_list(t_listp *list);
char	error(t_data *data);
void	end(t_data *data);

#endif