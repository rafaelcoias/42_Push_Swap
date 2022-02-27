#include "push_swap.h"

stack *ft_add_bottom(stack **s, stack *new)
{
    if (!s)
		return ;
	new->next = *s;
	*s = new;
}

stack *ft_add_top(stack **s, stack *new)
{
    stack	*aux;

	if (!s)
		return ;
	if (!(*s))
		*s = new;
	else
	{
		aux = get_top(*s);
		aux->next = new;
	}
}

stack *ft_rm(stack *s)
{
    if (s)
        free (s);
    s = NULL;
    return (s);
}
