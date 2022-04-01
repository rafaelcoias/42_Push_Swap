/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:42:20 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/08 22:08:57 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *s, int first)
{
	if (!s)
		return ;
	if (first)
		ft_putstr_fd("\nStack:\n\n", 1);
	if (s->next)
	{
		print_stack(s->next, 0);
		ft_putnbr_fd(s->nbr, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putnbr_fd(s->nbr, 1);
		ft_putchar_fd('\n', 1);
	}
	if (first)
		ft_putstr_fd("-\na\n", 1);
}
