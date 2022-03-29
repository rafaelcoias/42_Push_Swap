#include "../include/push_swap.h"

void	sort_medium(t_stack **a, t_stack **b)
{
	int	bigger;
	int	div;
	int	aux;

	bigger = get_bigger(*a);
	div = bigger / 5;
	aux = div;
	while (aux < bigger)
	{
		while (handle_sort_a(a, div, aux))
		{
			handle_sort_b(b);
			do_pb(a, b);
		}
		aux = aux + div;
	}
	while (get_size(*b))
	{
		re_push(b);
		do_pa(a, b);
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	bigger;
	int	div;
	int	aux;

	bigger = get_bigger(*a);
	div = bigger / 11;
	aux = div;
	while (aux < bigger)
	{
		while (handle_sort_a(a, div, aux))
		{
			handle_sort_b(b);
			do_pb(a, b);
		}
		aux = aux + div;
	}
	while (get_size(*b))
	{
		re_push(b);
		do_pa(a, b);
	}
}