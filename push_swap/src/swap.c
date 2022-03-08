/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:50:59 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:53:04 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **s)
{
	int		top;
	int		top2;
	t_stack	*aux;

	if (!(s && get_size(*s) > 1))
		return ;
	top = get_top(*s)->nbr;
	top2 = get_top(*s)->last->nbr;
	aux = *s;
	while ((aux)->next)
		aux = (aux)->next;
	(aux)->last->nbr = top;
	aux->nbr = top2;
	while ((aux)->last)
		aux = (aux)->last;
	*s = aux;
}

void	do_sa(t_stack **s)
{
	swap(s);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **s)
{
	swap(s);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
