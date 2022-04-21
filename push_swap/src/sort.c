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

void	sort(int argc, t_stack *a, t_stack *b, t_flags *f)
{
	if (argc == 2)
		sort_two_a(&a, &b, f);
	else if (argc == 3)
		sort_three_a(&a, &b, f);
	else if (argc <= 6)
		sort_five(&a, &b, f);
	else if (argc <= 100)
		sort_hundreds(&a, &b, 5, f);
	else if (argc <= 500)
		sort_hundreds(&a, &b, 11, f);
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
