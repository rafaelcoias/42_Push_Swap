/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:41:47 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:45:34 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_sort_b(t_stack **s)
{
	int	smaller;

	if (get_size(*s) < 2)
		return ;
	smaller = get_smaller(*s);
	if (top_b(get_top(*s), smaller) <= bottom_b(get_bottom(*s), smaller))
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

	bigger = get_bigger(*s);
	if (top_b(get_top(*s), bigger) <= bottom_b(get_bottom(*s), bigger))
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
		//iterar s
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
