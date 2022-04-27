/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:50:59 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/26 11:53:43 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **s)
{
	int		aux;

	aux = (*s)->nbr;
	(*s)->nbr = (*s)->next->nbr;
	(*s)->next->nbr = aux;
}

void	do_sa(t_stack **a, t_stack **b, t_flags *f)
{
	char	n;

	swap(a);
	write(1, "sa\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
	if (f->debug)
	{
		ft_putstr_fd("         \033[0;33m(continue)\033[0m", 1);
		scanf("%c", &n);
	}
}

void	do_sb(t_stack **a, t_stack **b, t_flags *f)
{
	char	n;

	swap(b);
	write(1, "sb\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
	if (f->debug)
	{
		ft_putstr_fd("         \033[0;33m(continue)\033[0m", 1);
		scanf("%c", &n);
	}
}

void	do_ss(t_stack **a, t_stack **b, t_flags *f)
{
	char	n;

	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	f->count = f->count + 1;
	if (f->view)
		print_stack_a_and_b(*a, *b, 1, f);
	if (f->debug)
	{
		ft_putstr_fd("         \033[0;33m(continue)\033[0m", 1);
		scanf("%c", &n);
	}
}
