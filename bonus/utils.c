#include "checker.h"

int	check_sort(t_data *data)
{
	t_listp	*lst;
	int		i;

	lst = data->a_stack;
	i = size_stack(lst);
	while (i >= 0)
	{
		if (lst->next->order != (lst->order + 1))
			return (1);
		i--;
		lst = lst->next;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	check_dub(char **av)
{
	int	i;
	int	n;

	i = 0;
	while (av[i])
	{
		n = 0;
		while (av[n] && i != n)
		{
			if (!ft_strcmp(av[i], av[n]))
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}