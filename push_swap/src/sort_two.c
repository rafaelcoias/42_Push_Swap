/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:23:43 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:23:52 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two_a(t_stack **a, t_stack **b, t_flags *f)
{
	if (!is_sorted(a))
		do_sa(a, b, f);
	return ;
}

void	sort_two_b(t_stack **a, t_stack **b, t_flags *f)
{
	if (!is_sorted(b))
		do_sb(a, b, f);
	return ;
}
