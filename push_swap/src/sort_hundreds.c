/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundreds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:22:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:22:58 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*

Sort hundreds functions basically divides the stack into
smaller stacks to be easier and faster to sort.

It will save the biggest number of the stack and will divide 
the stack depending on that number. While the function does 
not reach the last mini stack (while aux < bigger) it will
organize b stack and push the numbers in stack a to stack b.

When handle_sort_a function cannot find a number in the range 
of the mini stack, it is going to handle_sort_b. This function
is going to sort stack b in a way that stack b is sorted from
smallest to biggest.

Finally, when all of the numbers in stack a are in stack b, it 
is time to re_push every number again to stack a.

*/

void	sort_hundreds(t_stack **a, t_stack **b, int divide)
{
	int	bigger;
	int	div;
	int	aux;

	bigger = get_biggest(*a);
	div = bigger / divide;
	aux = div;
	while (aux <= bigger)
	{
		while (handle_sort_a(a, div, aux))
		{
			re_sort(b);
			do_pb(a, b);
		}
		aux = aux + div;
	}
	while (get_size(*a))
		do_pb(a, b);
	while (get_size(*b))
	{
		re_sort(b);
		do_pa(a, b);
	}
}
