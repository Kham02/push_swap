#include "checker.h"

void	error(t_data *data)
{
	write(1, "Error\n", 6);
	if (data->a_stack)
		free_lst(data->a_stack);
	if (data->b_stack)
		free_lst(data->b_stack);
	data = NULL;
	exit(EXIT_FAILURE);
}

void	end(t_data *data)
{
	if (check_sort(data->a_stack) && size_stack(data->b_stack) < 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (data->a_stack)
		free_lst(data->a_stack);
	if (data->b_stack)
		free_lst(data->b_stack);
	data = NULL;
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		error();
	data = (t_data *)malloc(sizeof(t_data *));
	if (!data)
		error(data);
	check_valid(data, av);
	reed_op(data);
	end(data);
	return (0);
}