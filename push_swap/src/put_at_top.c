/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:24:10 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:24:12 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_at_top_a(t_stack **s, int nbr)
{
	int	med;

	if (get_size(*s) < 2 || get_top(*s)->nbr == nbr)
		return ;
	med = get_size(*s) / 2;
	if (find_nbr_in_bottom(*s, nbr, med))
		while (get_top(*s)->nbr != nbr)
			do_ra(s);
	else
		while (get_top(*s)->nbr != nbr)
			do_rra(s);
}

void	put_at_top_b(t_stack **s, int nbr)
{
	int	med;

	if (get_size(*s) < 2 || get_top(*s)->nbr == nbr)
		return ;
	med = get_size(*s) / 2;
	if (find_nbr_in_bottom(*s, nbr, med))
		while (get_top(*s)->nbr != nbr)
			do_rb(s);
	else
		while (get_top(*s)->nbr != nbr)
			do_rrb(s);
}