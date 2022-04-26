/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:53:11 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/26 11:51:23 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*result;

	first = *s;
	result = (*s)->next;
	while ((*s)->next)
		*s = (*s)->next;
	(*s)->next = first;
	*s = result;
	first->next = NULL;
}

void	do_ra(t_stack **a, t_stack **b, t_flags *f)
{
	rotate(a);
	write(1, "ra\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
}

void	do_rb(t_stack **a, t_stack **b, t_flags *f)
{
	rotate(b);
	write(1, "rb\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
}

void	do_rr(t_stack **a, t_stack **b, t_flags *f)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
}
