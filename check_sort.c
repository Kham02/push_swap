#include "push_swap.h"

int	check_sort(t_data *data)
{
	data->str_int = data->a_stack->val;
	data->i = 1;
	while (data->i <= data->size_a)
	{
		if (data->str_int[data->i - 1] > data->str_int[data->i])
			return(1);
		data->i++;
	}
	return(0);
}

int	check_sort2(t_data *data)
{
	while (data->i > 0)
	{
		if (data->str_int[data->i - 1] < data->str_int[data->i])
			return(1);
		data->i--;
	}
	return(0);
}