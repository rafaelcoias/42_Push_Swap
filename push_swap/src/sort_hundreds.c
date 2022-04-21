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

void	sort_hundreds(t_stack **a, t_stack **b, int div, t_flags *f)
{
	int	v[2];

	v[0] = get_smallest(*a);
	v[1] = get_biggest(*a) / div;
	while (v[0] < get_biggest(*a))
	{
		while (find_range_in_stack(*a, v[0], v[0] + v[1]))
		{
			put_range_top_a(a, b, v, f);
			do_pb(a, b, f);
		}
		v[0] += v[1];
	}
	while (get_size(*a))
		do_pb(a, b, f);
	while (get_size(*b))
	{
		put_at_top_b(a, b, get_biggest(*b), f);
		do_pa(a, b, f);
	}
}
