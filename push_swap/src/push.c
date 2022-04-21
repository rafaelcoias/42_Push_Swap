/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:50:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:50:46 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	if (!b || get_size(*b) == 0)
		return ;
	ft_add_top(a, get_top(*b));
	ft_rm_top(b);
}

void	do_pa(t_stack **a, t_stack **b, t_flags *f)
{
	push(a, b);
	write(1, "pa\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
}

void	do_pb(t_stack **a, t_stack **b, t_flags *f)
{
	push(b, a);
	write(1, "pb\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
}
