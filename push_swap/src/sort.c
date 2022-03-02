#include "../include/push_swap.h"

void sort_three(stack **s)
{
    stack *first;
    stack *second;
    stack *third;

    if (!(*s))
        return ;
    first = *s;
    second = first->next;
    third = second->next;
    while (!is_sorted(*s))
    {
        if ((first->nbr > second->nbr && first->nbr > third->nbr) || (first->nbr < second->nbr && first->nbr < third->nbr && second->nbr < third->nbr) || (third->nbr < second->nbr && third->nbr < first->nbr))
            do_sa(s);
        else if (third->nbr > second->nbr && third->nbr > first->nbr && second->nbr < first->nbr)
            do_ra(s);
        else if (first->nbr < second->nbr && first->nbr < third->nbr)
            do_rra(s);
    }
}

void sort_small(stack **a, stack **b)
{
    stack *top_b;
    stack *top_a;

    top_b = NULL;
    top_a = NULL;
    do_pb(a, b);
    do_pb(a, b);
    sort_three(a);
    sort_three(b);
    while (!is_sorted(*a) || get_size(*b) > 0)
    {
        top_b = get_top(*b);
        top_a = get_top(*a);
        if (top_b->nbr > top_a->nbr)
            do_rra(a);
        else
            do_pb(a, b);
    }
    while (!is_sorted(*a))
        do_ra(a);
}

void sort_medium(stack **a, stack **b)
{
    int medium;
    int bigger;
    int div;
    int aux;

    medium = get_size(*a) / 2;
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

void sort_big(stack **a, stack **b)
{
    int medium;
    int bigger;
    int div;
    int aux;

    medium = get_size(*a) / 2;
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

int is_sorted(stack *s)
{
    int	i;

	i = s->nbr;
	while (s)
	{
		s = s->next;
        if (!s)
            continue ;
		if (s->nbr > i)
            return (0);
        i = s->nbr;
	}
	return (1);
}