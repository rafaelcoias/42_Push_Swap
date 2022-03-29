#include "../include/push_swap.h"

void    sort(int argc, t_stack *a, t_stack *b)
{
    print_stack(&a);
    if (argc == 3)
		sort_two(&a);
	else if (argc == 4)
		sort_three(&a);
	else if (argc <= 6)
		sort_five(&a, &b);
	else if (argc <= 101)
		sort_medium(&a, &b);
	else if (argc <= 501)
		sort_big(&a, &b);
    print_stack(&a);
}

int	is_sorted(t_stack **s)
{
	t_stack	*aux;

	aux = *s;
	while (aux)
	{
		if (aux->next && aux->next->nbr > aux->nbr)
			return (0);
		aux = aux->next;
	}
	return (1);
}