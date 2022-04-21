/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:43:41 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/21 14:47:31 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	sort_last_two(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	while (aux->next->next)
	{
		if (aux->next && aux->next->nbr > aux->nbr)
			return (0);
		aux = aux->next;
	}
	return (1);
}

static int	top_bigger_than_bottom(t_stack *bott, t_stack *top)
{
	t_stack	*first_top;

	first_top = top;
	while (bott != first_top)
	{
		top = first_top;
		while (top)
		{
			if (top->nbr < bott->nbr)
				return (0);
			top = top->next;
		}
		bott = bott->next;
	}
	return (1);
}

static int	is_semi_sorted_top(t_stack **a, t_stack *s)
{
	if (!top_bigger_than_bottom(*a, s))
		return (0);
	while (s->next)
	{
		if (s->next->nbr > s->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}

static int	is_semi_sorted_bottom(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	while (aux->next)
	{
		if (aux->next->nbr > aux->nbr)
			return (is_semi_sorted_top(a, aux->next));
		aux = aux->next;
	}
	return (0);
}

void	sort_easy(t_stack **a)
{
	if (is_semi_sorted_bottom(a))
		return (put_at_top_a(a, get_smallest(*a)));
	if (sort_last_two(a))
		return (do_sa(a));
	if (is_sorted(&(*a)->next))
		return (do_ra(a));
}
