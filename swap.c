#include "push_swap.h"

static void swap(stack **s)
{
    stack   *top;
    stack   *top2;

    if (!(s && get_size(*s) > 1))
        return ;
    top = get_top(*s);
    top2 = top->last;
    while ((*s)->next)
        *s = (*s)->next;
    (*s)->last = top;
    *s = top2;
}

void    do_sa(stack **s)
{
    swap(s);
    write(1, "sa\n", 3);
}

void    do_sb(stack **s)
{
    swap(s);
    write(1, "sb\n", 3);
}

void    do_ss(stack **a, stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}