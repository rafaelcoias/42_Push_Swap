/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:21:28 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:22:14 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_a_rotations(t_stack **a)
{
	t_stack	*aux;
	int		bigger;
	int		i;
	int		med;

	aux = *a;
	bigger = get_biggest(*a);
	i = 0;
	med = (get_size(*a) / 2) + 0.5;
	while (i <= med && aux->next)
	{
		if (aux->nbr == bigger)
		{
			while (!is_sorted(a))
				do_ra(a);
			return ;
		}
		aux = aux->next;
		i++;
	}
	while (!is_sorted(a))
		do_rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (get_size(*a) > 3)
		do_pb(a, b);
	sort_three(a);
	sort_two_b(b);
	while (get_size(*b) > 0)
	{
		if (get_biggest(*a) < get_top(*b)->nbr)
		{
			do_pa(a, b);
			do_rra(a);
			continue ;
		}
		if (get_top(*b)->nbr > get_top(*a)->nbr)
			do_rra(a);
		else
		{
			do_pa(a, b);
			if (get_top(*b) && get_biggest(*a) < get_top(*b)->nbr)
				sort_a_rotations(a);
		}
	}
	sort_a_rotations(a);
}
