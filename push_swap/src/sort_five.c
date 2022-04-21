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

void	sort_five(t_stack **a, t_stack **b, t_flags *f)
{
	while (get_size(*a) > 3)
		do_pb(a, b, f);
	sort_three_a(a, b, f);
	if (get_size(*b) == 3)
		sort_three_b(a, b, f);
	else
		sort_two_b(a, b, f);
	while (get_size(*b) > 0)
	{
		if (get_biggest(*a) < get_top(*b)->nbr)
		{
			do_pa(a, b, f);
			do_rra(a, b, f);
			continue ;
		}
		if (get_top(*b)->nbr > get_top(*a)->nbr)
			do_rra(a, b, f);
		else
			do_pa(a, b, f);
	}
	put_at_top_a(a, b, get_smallest(*a), f);
}
