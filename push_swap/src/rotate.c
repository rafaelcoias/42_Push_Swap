/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:53:11 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:53:56 by rade-sar         ###   ########.fr       */
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

void	do_ra(t_stack **s)
{
	rotate(s);
	write(1, "ra\n", 3);
}

void	do_rb(t_stack **s)
{
	rotate(s);
	write(1, "rb\n", 3);
}

void	do_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
