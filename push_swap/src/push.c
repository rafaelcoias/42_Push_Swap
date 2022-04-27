/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:50:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/26 11:51:01 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (!a)
		return ;
	aux_a = (*a)->next;
	aux_b = *a;
	*a = aux_a;
	aux_b->next = *b;
	*b = aux_b;
}

void	do_pa(t_stack **a, t_stack **b, t_flags *f)
{
	char	n;

	push(b, a);
	write(1, "pa\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
	if (f->debug)
	{
		ft_putstr_fd("         \033[0;33m(continue)\033[0m", 1);
		scanf("%c", &n);
	}
}

void	do_pb(t_stack **a, t_stack **b, t_flags *f)
{
	char	n;

	push(a, b);
	write(1, "pb\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
	if (f->debug)
	{
		ft_putstr_fd("         \033[0;33m(continue)\033[0m", 1);
		scanf("%c", &n);
	}
}
