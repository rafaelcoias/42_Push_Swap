#include "../include/push_swap.h"

static void push(stack **a, stack **b)
{
    stack   *top_b;
    
    if (!(b && get_size(*b) > 0))
        return ;
    top_b = get_top(*b);
    *a = ft_add_top(a, top_b);
}

void    do_pa(stack **a, stack **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    do_pb(stack **a, stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}