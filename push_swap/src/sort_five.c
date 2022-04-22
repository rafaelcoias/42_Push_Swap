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
	{
		put_at_top_a(a, b, get_smallest(*a), f);
		do_pb(a, b, f);
	}
	sort_three_a(a, b, f);
	while (get_size(*b) > 0)
	{
		put_at_top_b(a, b, get_biggest(*b), f);
		do_pa(a, b, f);
	}
	put_at_top_a(a, b, get_smallest(*a), f);
}
