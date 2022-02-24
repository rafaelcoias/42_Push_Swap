#include "push_swap.h"

stack   *get_bottom(stack *s)
{
    if (s == NULL)
		return (NULL);
	while (s->last)
		s = s->last;
	return (s);
}

stack   *get_top(stack *s)
{
	if (s == NULL)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int get_size(stack *s)
{
    int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}