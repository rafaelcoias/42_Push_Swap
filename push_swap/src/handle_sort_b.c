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
bottom_b function do).

It is going to rotate or reverse rotate until the number 
that we look for is in the top of the stack.

========================================================

re_push function does the same, but is looking for the 
biggest number on stack b.
*/

void	re_sort(t_stack **s)
{
	int	bigger;
	int	med;

	if (get_size(*s) < 2)
		return ;
	bigger = get_biggest(*s);
	med = get_size(*s) / 2;
	if (bottom_b(*s, bigger, med))
		while (get_top(*s)->nbr != bigger)
			do_rb(s);
	else
		while (get_top(*s)->nbr != bigger)
			do_rrb(s);
}

int	bottom_b(t_stack *s, int n, int med)
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
