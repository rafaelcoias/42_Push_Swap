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
        if ((first->nbr > second->nbr && first->nbr > third->nbr) 
            || (first->nbr < second->nbr && first->nbr < third->nbr && second->nbr < third->nbr) 
            || (third->nbr < second->nbr && third->nbr < first->nbr))
            do_sa(a);
        else if (third->nbr > second->nbr && third->nbr > first->nbr && second->nbr < first->nbr)
            do_ra(a);
        else if (first->nbr < second->nbr && first->nbr < third->nbr)
            do_rra(a);
    }
}

void sort_small(stack **a, stack **b)
{
    do_pb();
    do_pb();
    sort_three(&a);
    sort_three(&b);
    while (!is_sorted(a) || get_size(**b) > 0)
    {
        
    }
}

void sort_medium(stack **a, stack **b)
{
}

void sort_big(stack **a, stack **b)
{

}

int is_sorted(stack **a)
{

}