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

int	handle_sort_a(t_stack **s, int div, int aux)
{
	int	m;
	int	fst;
	int	lst;

	m = get_size(*s) / 2;
	fst = aux - div;
	lst = aux;
	if (!(top(get_top(*s), m, fst, lst) || bottom(*s, m, fst, lst)))
		return (0);
	if (top(get_top(*s), m, fst, lst) <= bottom(*s, m, fst, lst))
	{
		while (get_top(*s)->nbr != find_top(*s, aux - div, aux))
			do_rra(s);
	}
	else
	{
		while (get_top(*s)->nbr != find_top(*s, aux - div, aux))
			do_ra(s);
	}
	return (1);
}

int	top(t_stack *s, int m_pos, int first, int last)
{
	int	i;

	i = 1;
	while (s && i < m_pos)
	{
		if (s->nbr >= first && s->nbr <= last)
			return (i);
		i++;
	}
	return (0);
}

int	bottom(t_stack *s, int m_pos, int first, int last)
{
	int	i;

	i = 1;
	while (s && i < m_pos)
	{
		if (s->nbr >= first && s->nbr <= last)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}

int	find_top(t_stack *s, int first, int last)
{
	while (!(s->nbr >= first && s->nbr <= last))
		first++;
	return (s->nbr);
}

int	find_bottom(t_stack *s, int first, int last)
{
	while (!(s->nbr >= first && s->nbr <= last))
		s = s->next;
	return (s->nbr);
}
