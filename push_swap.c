#include "push_swap.h"

void	values(t_data *data)
{
	data->i = 0;
}

void	check(t_data *data, int ac, char **av)
{
	values(data);
	while (data->i <= ac - 1)
	{
		writing(data, av[data->i]);
		data->i++;
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
	
}