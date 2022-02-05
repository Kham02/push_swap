#include "push_swap.h"


int	main(int ac ,char **av)
{
	t_data	s;

	if (ac < 2)
		exit(1);
	if (!(s = (t_data *)malloc(sizeof(t_data))))
		exit(1);
	if (!(s->a_stack = (t_list *)malloc(sizeof(t_list))))
		exit(1);
	
}