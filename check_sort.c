#include "push_swap.h"

int	check_sort(t_data *data)
{
	data->a_stack->val = data->str_int;
	data->i = 1;
	while (data->i <= data->size_a)
	{
		if (data->str_int[data->i - 1] > data->str_int[data->i])
			return(1);
		data->i++;
	}
	return(0;)
}