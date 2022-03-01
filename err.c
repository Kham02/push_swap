#include "push_swap.h"

char	error(t_data *data)
{
	//напечатать Error
	exit(0);
	return(0);
}

void	free_all(t_data *data)
{
	
}

void	free2arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
}
