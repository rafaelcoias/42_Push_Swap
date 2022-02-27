#include "push_swap.h"

static void rotate(stack **s)
{
    if (!(s && get_size(*s) > 1))
        return;
    *s = ft_add_bottom(get_top(*s));
    while ((*s)->next)
        *s = (*s)->next;
    *s = ft_rm(*s);
}

void do_ra(stack **s)
{
    rotate(s);
    write(1, "ra\n", 3);
}

void do_rb(stack **s)
{
    rotate(s);
    write(1, "rb\n", 3);
}

void do_rr(stack **a, stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
