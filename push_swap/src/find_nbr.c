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

/*
Handle_sort_b function will check if the stack has less
than 2 numbers.

If it has more than 2 numbers it will rotate or reverse 
rotate the stack depending if the smallest number of the
stack is closer to the top or bottom (that is what the 
find_in_bottom function do).

It is going to rotate or reverse rotate until the number 
that we look for is in the top of the stack.

========================================================

re_push function does the same, but is looking for the 
biggest number on stack b.
*/

int	find_range_in_stack(t_stack *s, int first, int last)
{
	int	i;

	i = 1;
	while (s)
	{
		if (s->nbr >= first && s->nbr <= last)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}

int	find_nbr_in_bottom(t_stack *s, int n, int med)
{
	int	i;

	i = 1;
	while (s && i <= med)
	{
		if (s->nbr == n)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}

int	find_nbr_in_stack(t_stack *s, int nbr)
{
	if (!s)
		return (0);
	while (s->next)
	{
		if (s->nbr == nbr)
			return (1);
		s = s->next;
	}
	return (0);
}

int	find_smallest_in_range(int fst, int lst)
{
	int	min;

	min = fst;
	while (++fst != lst + 1)
		if (min < fst)
			min = fst;
	return (min);
}
