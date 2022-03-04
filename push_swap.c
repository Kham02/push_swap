#include "push_swap.h"

void	values(t_data *data)
{
	data->i = 2;
	data->str = ft_strdup("");
	data->min = 0;
	data->mid = 0;
	data->max = 0;
	data->next_order = 0;
	data->a_stack->next = NULL;
}

void	check(t_data *data, int ac, char **av)
{
	values(data);
	while (data->i <= ac - 1)
	{
		data->str = ft_strjoin(data->str, av[data->i]);
		data->i++;
	}
	check_valid(data);
	if (check_sort(data) == 0)
		//печатаем
	else
	{
		bub(t_data *data);
		if (data->size_a <= 100)
			sort_min(t_data *data);
		else
			qs(t_data *data);
	}
}

int	main(int ac ,char **av)
{
	t_data	data;

	if (ac < 2)
		error(data);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		error(data);
	if (!(data->a_stack = (t_list *)malloc(sizeof(t_list))))
		error(data);
	check(data, ac, av);
}