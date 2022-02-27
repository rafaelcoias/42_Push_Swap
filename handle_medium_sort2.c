#include "push_swap.h"

void handle_medium_b(stack **s)
{
    int smaller;

    if (get_size(b) < 2)
        return ;
    smaller = get_smaller(*s);
    if (top_b(get_top(*s), smaller) <= bottom_b(get_bottom(*s), smaller))
    {
        while (get_top(*s)->nbr != smaller)
            do_rb(s);
    }
    else
    {
        while (get_top(*s)->nbr != smaller)
            do_rrb(s);
    }
}

void re_push(stack **s)
{
    int bigger;

    bigger = get_bigger(*s);
    if (top_b(get_top(*s), bigger) <= bottom_b(get_bottom(*s), bigger))
    {
        while (get_top(*s)->nbr != bigger)
            do_rb(s);
    }
    else
    {
        while (get_top(*s)->nbr != bigger)
            do_rrb(s);
    }
}

int top_b(stack *s, int n)
{
    int i;

    i = 0;
    while (s)
    {
        if (s->nbr == n)
            return (i);
        i++;
        s = s->last;
    }
    return (i);
}

int bottom_b(stack *s, int n)
{
    int i;

    i = 0;
    while (s)
    {
        if (s->nbr == n)
            return (i);
        i++;
        s = s->next;
    }
    return (i);
}