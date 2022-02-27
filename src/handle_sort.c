#include "push_swap.h"

int handle_sort_a(stack **s, int div, int aux)
{
    int medium;

    medium = get_size(*s) / 2;
    if (!(top(get_top(*s), medium, aux - div, aux) || bottom(get_bottom(*s), medium, aux - div, aux)))
        return (0);
    if (top(get_top(*s), medium, aux - div, aux) <= bottom(get_bottom(*s), medium, aux - div, aux))
    {
        while (get_top(*s)->nbr != find_top(get_top(*s), aux - div, aux))
            do_ra(s);
    }
    else
    {
        while (get_top(*s)->nbr != find_top(get_top(*s), aux - div, aux))
            do_rra(s);
    }
    return (1);
}

int top(stack *s, int medium_pos, int first, int last)
{
    int i;

    i = 1;
    while (s && i < medium_pos)
    {
        if (s->nbr >= first && s->nbr <= last)
            return (i);
        i++;
        s = s->last;
    }
    return (0);
}

int bottom(stack *s, int medium_pos, int first, int last)
{
    int i;

    i = 1;
    while (s && i < medium_pos)
    {
        if (s->nbr >= first && s->nbr <= last)
            return (i);
        i++;
        s = s->next;
    }
    return (0);
}

int find_top(stack *s, int first, int last)
{
    while (!(s->nbr >= first && s->nbr <= last))
        s = s->last;
    return (s->nbr);
}

int find_bottom(stack *s, int first, int last)
{
    while (!(s->nbr >= first && s->nbr <= last))
        s = s->next;
    return (s->nbr);
}