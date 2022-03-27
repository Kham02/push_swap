#include "checker.h"

int	size_stack(t_listp *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (-1);
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_listp	*lst_new(int val)
{
	t_listp	*new_list;

	new_list = malloc(sizeof(t_listp));
	if (!new_list)
		return (NULL);
	new_list->val = val;
	new_list->order = -1;
	new_list->flag = 0;
	new_list->next = NULL;
	return (new_list);
}

void	lst_add_back(t_listp **lst, t_listp *new_lst)
{
	t_listp	*tmp;

	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
	else
		*lst = new_lst;
}