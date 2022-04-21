/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_at_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:40:51 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/21 14:40:53 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_range_top_a(t_stack **a, t_stack **b, int v[2], t_flags *f)
{
	int	med;
	int	fst;
	int	lst;

	fst = v[0];
	lst = v[0] + v[1];
	if (get_size(*a) < 2
		|| (get_top(*a)->nbr >= fst && get_top(*a)->nbr <= lst))
		return ;
	med = get_size(*a) / 2;
	if (find_range_in_bottom(*a, fst, lst, med))
		while (!(get_top(*a)->nbr >= fst && get_top(*a)->nbr <= lst))
			do_ra(a, b, f);
	else
		while (!(get_top(*a)->nbr >= fst && get_top(*a)->nbr <= lst))
			do_rra(a, b, f);
}

void	put_at_top_a(t_stack **a, t_stack **b, int nbr, t_flags *f)
{
	int	med;

	if (get_size(*a) < 2 || get_top(*a)->nbr == nbr)
		return ;
	med = get_size(*a) / 2;
	if (find_nbr_in_bottom(*a, nbr, med))
		while (get_top(*a)->nbr != nbr)
			do_ra(a, b, f);
	else
		while (get_top(*a)->nbr != nbr)
			do_rra(a, b, f);
}

void	put_at_top_b(t_stack **a, t_stack **b, int nbr, t_flags *f)
{
	int	med;

	if (get_size(*b) < 2 || get_top(*b)->nbr == nbr)
		return ;
	med = get_size(*b) / 2;
	if (find_nbr_in_bottom(*b, nbr, med))
		while (get_top(*b)->nbr != nbr)
			do_rb(a, b, f);
	else
		while (get_top(*b)->nbr != nbr)
			do_rrb(a, b, f);
}
