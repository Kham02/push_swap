/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:18:15 by estrong           #+#    #+#             */
/*   Updated: 2022/03/27 20:39:45 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include "../Libft/libft.h"
#include "get_next_line.h"

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
void	lst_add_back(t_listp **lst, t_listp *new_lst);
void	check_valid(t_data *data, char **av);
int		check_dub(char **av);
int		ft_strcmp(char *s1, char *s2);
int		check_sort(t_data *data);
int		push_swap_atoi(t_data *data, char *str, unsigned int n, int s);
void	reed_op(t_data *data);
void	check_op(t_data *data, char *str);
void	error(t_data *data);
void	free_list(t_listp *list);
void	end(t_data *data);

#endif