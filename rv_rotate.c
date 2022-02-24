#include "push_swap.h"

static void rv_rotate(stack **s)
{
    stack *aux;

    if (!(s && get_size(*s) > 1))
        return;
    aux = (*s)->next;
    aux = ft_add_top(get_bottom(*s));
    *s = aux;
}

void do_rra(stack **s)
{
    rv_rotate(s);
    write(1, "rra\n", 3);
}

void do_rrb(stack **s)
{
    rv_rotate(s);
    write(1, "rrb\n", 3);
}

void do_rrr(stack **a, stack **b)
{
    rv_rotate(a);
    rv_rotate(b);
    write(1, "rrr\n", 4);
}