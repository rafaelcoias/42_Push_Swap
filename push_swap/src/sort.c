/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:56:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 16:02:26 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **s)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!(*s))
		return ;
	a = *s;
	b = a->next;
	c = b->next;
	while (!is_sorted(s))
	{
		if ((a->nbr > b->nbr && a->nbr > c->nbr)
			|| (a->nbr < b->nbr && a->nbr < c->nbr && b->nbr < c->nbr)
			|| (c->nbr < b->nbr && c->nbr < a->nbr))
			do_sa(s);
		else if (c->nbr > b->nbr
			&& c->nbr > a->nbr
			&& b->nbr < a->nbr)
			do_ra(s);
		else if (a->nbr < b->nbr && a->nbr < c->nbr)
			do_rra(s);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*top_b;
	t_stack	*top_a;

	top_b = NULL;
	top_a = NULL;
	do_pb(a, b);
	do_pb(a, b);
	sort_three(a);
	sort_two(b);
	while (!is_sorted(a) || get_size(*b) > 0)
	{
		top_b = get_top(*b);
		top_a = get_top(*a);
		if (top_b->nbr > top_a->nbr)
			do_rra(a);
		else
			do_pb(a, b);
	}
	while (!is_sorted(a))
		do_ra(a);
}

void	sort_medium(t_stack **a, t_stack **b)
{
	int	medium;
	int	bigger;
	int	div;
	int	aux;

	medium = get_size(*a) / 2;
	bigger = get_bigger(*a);
	div = bigger / 5;
	aux = div;
	while (aux < bigger)
	{
		while (handle_sort_a(a, div, aux))
		{
			handle_sort_b(b);
			do_pb(a, b);
		}
		aux = aux + div;
	}
	while (get_size(*b))
	{
		re_push(b);
		do_pa(a, b);
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	medium;
	int	bigger;
	int	div;
	int	aux;

	medium = get_size(*a) / 2;
	bigger = get_bigger(*a);
	div = bigger / 11;
	aux = div;
	while (aux < bigger)
	{
		while (handle_sort_a(a, div, aux))
		{
			handle_sort_b(b);
			do_pb(a, b);
		}
		aux = aux + div;
	}
	while (get_size(*b))
	{
		re_push(b);
		do_pa(a, b);
	}
}

int	is_sorted(t_stack **s)
{
	t_stack	*aux;

	aux = *s;
	while (aux)
	{
		if (aux->next && aux->next->nbr > aux->nbr)
			return (0);
		aux = aux->next;
	}
	return (1);
}
