/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:20:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:21:23 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(int argc, t_stack *a, t_stack *b)
{
	//print_stack(a, 1);
	//ft_putstr_fd("\nOperations:\n\n", 1);
	if (argc == 3)
		sort_two_a(&a);
	else if (argc == 4)
		sort_three(&a);
	else if (argc <= 6)
		sort_five(&a, &b);
	else if (argc <= 101)
		sort_hundreds(&a, &b, 5);
	else if (argc <= 501)
		sort_hundreds(&a, &b, 11);
	//print_stack(a, 1);
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
