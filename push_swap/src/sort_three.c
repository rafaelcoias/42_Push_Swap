/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:23:07 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:23:26 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_a(t_stack **a, t_stack **b, t_flags *f)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	if (!(*a))
		return ;
	z = *a;
	y = z->next;
	x = y->next;
	while (!is_sorted(a))
	{
		if ((x->nbr > y->nbr && x->nbr > z->nbr)
			|| (x->nbr < y->nbr && x->nbr < z->nbr && y->nbr < z->nbr)
			|| (z->nbr < y->nbr && z->nbr < x->nbr))
			do_sa(a, b, f);
		else if (z->nbr > y->nbr
			&& z->nbr > x->nbr
			&& y->nbr < x->nbr)
			do_ra(a, b, f);
		else if (x->nbr < y->nbr && x->nbr < z->nbr)
			do_rra(a, b, f);
	}
}

void	sort_three_b(t_stack **a, t_stack **b, t_flags *f)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	if (!(*b))
		return ;
	z = *b;
	y = z->next;
	x = y->next;
	while (!is_sorted(b))
	{
		if ((x->nbr > y->nbr && x->nbr > z->nbr)
			|| (x->nbr < y->nbr && x->nbr < z->nbr && y->nbr < z->nbr)
			|| (z->nbr < y->nbr && z->nbr < x->nbr))
			do_sb(a, b, f);
		else if (z->nbr > y->nbr
			&& z->nbr > x->nbr
			&& y->nbr < x->nbr)
			do_rb(a, b, f);
		else if (x->nbr < y->nbr && x->nbr < z->nbr)
			do_rrb(a, b, f);
	}
}
