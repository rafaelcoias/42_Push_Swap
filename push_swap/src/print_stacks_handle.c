/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:19:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:37 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	spaces(int total)
{
	int	i;

	i = -1;
	while (++i != total)
		ft_putchar_fd(' ', 1);
}

void	print_b_bigger_handler(t_stack *a, t_stack *b)
{
	if (a)
	{
		ft_putnbr_fd(a->nbr, 1);
		spaces(11 - ft_strlen(ft_itoa(b->nbr)));
	}
	else
		spaces(11);
	spaces(16 - ft_strlen(ft_itoa(b->nbr)));
	ft_putnbr_fd(b->nbr, 1);
	ft_putchar_fd('\n', 1);
}

void	print_a_bigger_handler(t_stack *a, t_stack *b)
{
	spaces(11 - ft_strlen(ft_itoa(a->nbr)));
	ft_putnbr_fd(a->nbr, 1);
	if (b)
	{
		spaces(16 - ft_strlen(ft_itoa(b->nbr)));
		ft_putnbr_fd(b->nbr, 1);
	}
	ft_putchar_fd('\n', 1);
}
