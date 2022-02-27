#include "push_swap.h"

static stack *ft_add(int n, stack *aux)
{
    stack *new;

    new = malloc(sizeof(stack));
    if (!new)
        return (NULL);
    new->last = aux;
    new->nbr = n;
    new->next = NULL;
    return (new);
}

static stack *stack_a(stack **a, char **argv, int argc)
{
    int     i;
    stack   *aux;

    i = 1;
    if (!a || !(*a))
        return (0);
    aux = NULL;
    while (i != argc)
    {
        *a = ft_add(ft_atol(argv[i]), aux);
        aux = *a;
        *a = (*a)->next;
        i++;
    }
    return (*a);
}

int main(int argc, char **argv)
{
    stack *a;
    stack *b;

    check_args(argc, argv);
    if (!a || !b)
        return (0);
    a = stack_a(&a, argv, argc);
    if (is_sorted(a))
        exit(0);
    if (argc <= 4)
        sort_three(&a);
    else if (argc <= 6)
        sort_small(&a, &b);
    else if (argc <= 101)
        sort_medium(&a, &b);
    else if (argc <= 501)
        sort_big(&a, &b);
    free(a);
    free(b);
    return (0);
}