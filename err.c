#include "push_swap.h"

char	error(t_data *data, char *mes)
{
	exit(0);
	return(0);
}

void	free(char **str)
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

char	delstr(char	*str)
{

}