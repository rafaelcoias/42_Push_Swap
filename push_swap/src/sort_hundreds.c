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

void	sort_hundreds(t_stack **a, t_stack **b)
{
    while (get_size(*a) > 3)
    {
        put_at_top_a(a, get_smallest(*a));
        do_pb(a, b);
    }
	sort_three(a);
	while (get_size(*b))
	{
		put_at_top_b(b, get_biggest(*b));
		do_pa(a, b);
	}
}
