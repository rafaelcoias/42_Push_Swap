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

void	print_stack(t_stack **s)
{
	t_stack	*aux;

	if (!s || !(*s))
		return ;
	aux = get_top(*s);
	ft_putstr_fd("\nStack:\n\n", 1);
	while (aux)
	{
		ft_putnbr_fd(aux->nbr, 1);
		ft_putchar_fd('\n', 1);
		aux = aux->last;
	}
	ft_putstr_fd("-\na\n", 1);
}
