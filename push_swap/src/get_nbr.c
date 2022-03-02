#include "../include/push_swap.h"

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

int get_bigger(stack *s)
{
    int	i;

	i = s->nbr;
	while (s)
	{
		s = s->next;
		if (s && s->nbr > i)
			i = s->nbr;
	}
	return (i);
}

int	get_smaller(stack *s)
{
	    int	i;

	i = s->nbr;
	while (s)
	{
		s = s->next;
		if (s && s->nbr < i)
			i = s->nbr;
	}
	return (i);
}