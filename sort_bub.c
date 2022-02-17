#include "push_swap.h"

void	bub(t_data *data)
{
	data->str_int = data->b_stack->val;
	data->i = 1;
	while (data->i <= data->size_b)
	{
		if (data->str_int[data->i - 1] > data->str_int[data->i])
		{
			data->val_bub = data->str_int[data->i - 1];
			data->str_int[data->i - 1] = data->str_int[data->i];
			data->str_int[data->i] = data->val_bub;
			if (data->str_int[data->i - 1] == data->str_int[data->i])
				error(data);
		}
		data->i++;
	}
}

