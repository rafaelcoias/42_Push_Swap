#include "push_swap.h"

int stack_length(stack s)
{
    int	i;

	i = 0;
	while (s.next)
	{
		s = s->next;
		i++;
	}
	return (i);
}