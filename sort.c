#include "push_swap.h"

void sort_three(stack **a)
{
    stack *first;
    stack *second;
    stack *third;

    first = *a;
    second = first->next;
    third = second->next;
    while (!is_sorted(a))
    {
        if ((first->nbr > second->nbr && first->nbr > third->nbr) || (first->nbr < second->nbr && first->nbr < third->nbr && second->nbr < third->nbr) || (third->nbr < second->nbr && third->nbr < first->nbr))
            do_sa(a);
        else if (third->nbr > second->nbr && third->nbr > first->nbr && second->nbr < first->nbr)
            do_ra(a);
        else if (first->nbr < second->nbr && first->nbr < third->nbr)
            do_rra(a);
    }
}

void sort_small(stack **a, stack **b)
{
    stack *top_b;
    stack *top_a;

    top_b = NULL;
    top_a = NULL;
    do_pb();
    do_pb();
    sort_three(a);
    sort_three(b);
    while (!is_sorted(a) || get_size(**b) > 0)
    {
        top_b = get_top(b);
        top_a = get_top(a);
        if (top_b->nbr > top_a->nbr)
            do_rra(a);
        else
            do_pb(a, b);
    }
    while (!is_sorted(a))
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
        while (handle_medium_a(a, div, aux))
        {
            handle_medium_b(b);
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
}

int is_sorted(stack **a)
{
}