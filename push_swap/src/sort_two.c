/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:56:04 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 16:02:26 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two_a(t_stack **a)
{
	if (!is_sorted(a))
		do_sa(a);
	return ;
}

void	sort_two_b(t_stack **b)
{
	if (!is_sorted(b))
		do_sb(b);
	return ;
}

