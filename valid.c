#include "push_swap.h"

static void	null_null(t_data *data)
{
	data->j = 0;
	data->i = 0;
	data->size_a = 0;
	data->size_b = 0;
	data->next_order = 1;
	data->a_stack->next = data->a_stack;
	data->a_stack->prev = data->a_stack;
	data->stack = NULL;
	data->a_stack->order = 0;
	data->a_stack->flag = 0;
}

void	check_valid(t_data *data)
{
	data->i = 0;
	while (data->str[data->i] || ft_isdigit(data->str[data->i]) || data->str[data->i] == 9 || 
		data->str[data->i] == 13 || data->str[data->i] == 32 || data->str[data->i] == ',' || 
		data->str[data->i] == '+' || data->str[data->i] == '-')
		data->i++;
	if (data->str[data->i] != '\0')
		error(data);
	mp(data);
}

static void	mp(t_data *data)
{
	null_null(data);
	while (data->str[data->i])
	{
		if (ft_isdigit(data->str[data->i]) || data->str[data->i] == '-' || data->str[data->i] == '+')
		{
			while (ft_isdigit(data->str[data->i]) || data->str[data->i] == '-' || data->str[data->i] == '+')
				data->i++;
			data->a_stack->val = push_swap_atoi(data, 0, 1);
			data->size_a++;
		}
		data->i++;
	}
	data->str = ft_strdup("");
}

int	push_swap_atoi(t_data *data, unsigned int n, int s)
{
	while ((data->str[data->j] > 8 && data->str[data->j] < 14) || data->str[data->j] == 32 || data->str[data->j] == ',')
		data->j++;
	if (data->str[data->j] == '-')
	{
		data->j++;
		s = -1;
	}
	if (data->str[data->j] == '+' && s == 1)
		data->j++;
	while (data->str[data->j] > 47 && data->str[data->j] < 58)
	{
		n = n * 10 + (data->str[data->j] - '0');
		data->j++;
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			error(data);
	}
	return(n * s);
}