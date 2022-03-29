#include "../include/push_swap.h"

void	sort_three(t_stack **s)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!(*s))
		return ;
	a = *s;
	b = a->next;
	c = b->next;
	while (!is_sorted(s))
	{
		if ((a->nbr > b->nbr && a->nbr > c->nbr)
			|| (a->nbr < b->nbr && a->nbr < c->nbr && b->nbr < c->nbr)
			|| (c->nbr < b->nbr && c->nbr < a->nbr))
			do_sa(s);
		else if (c->nbr > b->nbr
			&& c->nbr > a->nbr
			&& b->nbr < a->nbr)
			do_rra(s);
		else if (a->nbr < b->nbr && a->nbr < c->nbr)
			do_ra(s);
	}
}