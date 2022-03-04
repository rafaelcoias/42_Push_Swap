/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:54:06 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:55:08 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rv_rotate(t_stack **s)
{
	t_stack	*aux;

	if (!(s && get_size(*s) > 1))
		return ;
	aux = (*s)->next;
	aux = ft_add_top(s, get_bottom(*s));
	*s = aux;
}

void	do_rra(t_stack **s)
{
	rv_rotate(s);
	write(1, "rra\n", 3);
}

void	do_rrb(t_stack **s)
{
	rv_rotate(s);
	write(1, "rrb\n", 3);
}

void	do_rrr(t_stack **a, t_stack **b)
{
	rv_rotate(a);
	rv_rotate(b);
	write(1, "rrr\n", 4);
}