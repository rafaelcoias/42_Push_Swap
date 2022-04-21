/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundreds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:22:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:22:58 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_hundreds(t_stack **a, t_stack **b, int div)
{
	int	smallest;
	int	add;

	smallest = get_smallest(*a);
	add = get_biggest(*a) / div;
	while (smallest < get_biggest(*a))
	{
		while (find_range_in_stack(*a, smallest, smallest + add))
		{
			put_range_at_top_a(a, smallest, smallest + add);
			do_pb(a, b);
		}
		smallest += add;
	}
	while (get_size(*a))
		do_pb(a, b);
	while (get_size(*b))
	{
		put_at_top_b(b, get_biggest(*b));
		do_pa(a, b);
	}
}
