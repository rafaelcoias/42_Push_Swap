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

void	sort_five(t_stack **a, t_stack **b)
{
	while (get_size(*a) > 3)
		do_pb(a, b);
	sort_three(a);
    if (get_size(*b) == 3)
		sort_three_b(b);
    else
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
			do_pa(a, b);
    }
	put_at_top_a(a, get_smallest(*a));
}
