/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:24:10 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:24:12 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
handle_sort_a function will check if there is, or isn't, 
any number that corresponds that corresponds to one of
the range first/last.

If there is, it will rotate or reverse rotate the stack, 
depending if it is closer to the top or bottom (that is 
what the bottom function do - if until de middle of the
stack it cannot find the number, it means the number
is closer to the top).

It is going to rotate or reverse rotate until the number 
that we look for is at the top, or bottom (depending on
what extrem is closer) of the stack.
*/

int	handle_sort_a(t_stack **s, int div, int aux)
{
	int	m;
	int	fst;
	int	lst;

	m = get_size(*s) / 2;
	fst = aux - div;
	lst = aux;
	if (!find(*s, fst, lst))
		return (0);
	if (!bottom(*s, m, fst, lst))
		while (!(get_top(*s)->nbr >= fst && get_top(*s)->nbr <= lst))
			do_rra(s);
	else
		while (!(get_top(*s)->nbr >= fst && get_top(*s)->nbr <= lst))
			do_ra(s);
	return (1);
}

int	bottom(t_stack *s, int m_pos, int first, int last)
{
	int	i;

	i = 1;
	while (s && i <= m_pos)
	{
		if (s->nbr >= first && s->nbr <= last)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}
