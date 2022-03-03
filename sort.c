#include "push_swap.h"

void	qs(t_data *data)
{
	data->mid = data->size_a / 2;
	data->i = 0;
	while (data->i <= data->size_a)
	{
		if (data->a_stack->val <= data->mid)
			PUSH_B;
		else
			ROTATE_A;
		data->i++;
	}
	
}