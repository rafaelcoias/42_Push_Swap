/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:24:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:24:47 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_sort_b(t_stack **s)
{
	int	smaller;

	if (get_size(*s) < 2)
		return ;
	smaller = get_smallest(*s);
	if (top_b(get_top(*s), smaller) <= bottom_b(*s, smaller))
	{
		while (get_top(*s)->nbr != smaller)
			do_rrb(s);
	}
	else
	{
		while (get_top(*s)->nbr != smaller)
			do_rb(s);
	}
}

void	re_push(t_stack **s)
{
	int	bigger;

	bigger = get_biggest(*s);
	if (top_b(get_top(*s), bigger) <= bottom_b(*s, bigger))
	{
		while (get_top(*s)->nbr != bigger)
			do_rb(s);
	}
	else
	{
		while (get_top(*s)->nbr != bigger)
			do_rrb(s);
	}
}

int	top_b(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->nbr == n)
			return (i);
		i++;
	}
	return (i);
}

int	bottom_b(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->nbr == n)
			return (i);
		i++;
		s = s->next;
	}
	return (i);
}
