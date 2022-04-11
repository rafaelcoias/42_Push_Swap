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
	if (argc == 3)
		sort_two_a(&a);
	else if (argc == 4)
		sort_three(&a);
	else if (argc <= 7)
		sort_five(&a, &b);
	else
		sort_hundreds(&a, &b);
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
