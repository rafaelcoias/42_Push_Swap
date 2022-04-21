/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:39:06 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/21 14:39:09 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_stack_limit(void)
{
	ft_putstr_fd("-----------     -----------\n", 1);
	ft_putstr_fd("     A               B     \n\n", 1);
}

static void	spaces(int total)
{
	int	i;

	i = -1;
	while (++i != total)
		ft_putchar_fd(' ', 1);
}

void	print_a_bigger(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;
	if (a->next)
	{
		if (b)
			print_stack_a_and_b(a->next, b->next, 0);
		else
			print_stack_a_and_b(a->next, b, 0);
		spaces(11 - ft_strlen(ft_itoa(a->nbr)));
		ft_putnbr_fd(a->nbr, 1);
		if (b)
		{
			spaces(16 - ft_strlen(ft_itoa(b->nbr)));
			ft_putnbr_fd(b->nbr, 1);
		}
		ft_putchar_fd('\n', 1);
	}
	else
		print_a_bigger_handler(a, b);
}

void	print_b_bigger(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;
	if (b->next)
	{
		if (a)
		{
			print_stack_a_and_b(a->next, b->next, 0);
			spaces(11 - ft_strlen(ft_itoa(a->nbr)));
			ft_putnbr_fd(a->nbr, 1);
		}
		else
		{
			print_stack_a_and_b(a, b->next, 0);
			spaces(11);
		}
		spaces(16 - ft_strlen(ft_itoa(b->nbr)));
		ft_putnbr_fd(b->nbr, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		print_b_bigger_handler(a, b);
}

void	print_stack_a_and_b(t_stack *a, t_stack *b, int first)
{
	if (!a && !b)
		return ;
	if (first)
		ft_putstr_fd("\nStacks:\n\n", 1);
	if (get_size(a) >= get_size(b))
		print_a_bigger(a, b);
	else
		print_b_bigger(a, b);
	if (first)
		print_stack_limit();
}
