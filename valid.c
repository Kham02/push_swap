#include "push_swap.h"

void	null_null(t_data *data)
{
	data->j = 0;
	data->i = 0;
	data->stack->val = 0;
	data->stack->order = 0;
	data->stack->flag = 0;
}

void	check_valid(t_data *data)
{
	data->i = 0;
	while (data->str[data->i] || ft_isdigit(data->str[data->i]) || data->str[data->i] == 9 || 
		data->str[data->i] == 13 || data->str[data->i] == 32 || data->str[data->i] == ',' || 
		data->str[data->i] == '+' || data->str[data->i] == '-')
		data->i++;
	if (data->str[data->i] != '\n')
		error(data);
	mp(data);
}

void	mp(t_data *data)
{
	null_null(data);
	while (data->str[data->i])
	{
		if (ft_isdigit(data->str[data->i]) || data->str[data->i] == '-' || data->str[data->i] == '+')
		{
			data->j = data->i;
			while (ft_isdigit(data->str[data->i]) || data->str[data->i] == '-' || data->str[data->i] == '+')
				data->i++;
			data->stack->val = push_swap_atoi(data, 0, 1);
		}
		data->i++;
	}
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