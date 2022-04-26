/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_at_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:40:51 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/26 11:51:10 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*moves_b(t_stack **b, int nbr)
{
	int	med;

	if (get_size(*b) < 2 || (*b)->nbr == nbr)
		return (NULL);
	med = get_size(*b) / 2;
	if (find_nbr_in_bottom(*b, nbr, med))
		return ("rb");
	return ("rrb");
}

static int	mv_a(t_stack **a, t_stack **b, t_flags *f, char *mv_a)
{
	char	*mv_b;

	mv_b = moves_b(b, get_biggest(*b));
	if (!mv_b)
		return (1);
	if (!ft_strcmp(mv_a, "ra") && !ft_strcmp(mv_b, "rb"))
	{
		do_rr(a, b, f);
		return (0);
	}
	if (!ft_strcmp(mv_a, "rra") && !ft_strcmp(mv_b, "rrb"))
	{
		do_rrr(a, b, f);
		return (0);
	}
	if (!ft_strcmp(mv_a, "ra") && !ft_strcmp(mv_b, "rrb"))
		do_rrb(a, b, f);
	if (!ft_strcmp(mv_a, "rra") && !ft_strcmp(mv_b, "rb"))
		do_rb(a, b, f);
	return (1);
}

void	put_range_top_a(t_stack **a, t_stack **b, int v[2], t_flags *f)
{
	int	med;
	int	fst;
	int	lst;

	fst = v[0];
	lst = v[0] + v[1];
	if (get_size(*a) < 2
		|| ((*a)->nbr >= fst && (*a)->nbr <= lst))
		return ;
	med = get_size(*a) / 2;
	if (find_range_in_bottom(*a, fst, lst, med))
	{
		while (!((*a)->nbr >= fst && (*a)->nbr <= lst))
			if (mv_a(a, b, f, "ra"))
				do_ra(a, b, f);
	}
	else
		while (!((*a)->nbr >= fst && (*a)->nbr <= lst))
			if (mv_a(a, b, f, "rra"))
				do_rra(a, b, f);
}

void	put_at_top_a(t_stack **a, t_stack **b, int nbr, t_flags *f)
{
	int	med;

	if (get_size(*a) < 2 || (*a)->nbr == nbr)
		return ;
	med = get_size(*a) / 2;
	if (find_nbr_in_bottom(*a, nbr, med))
		while ((*a)->nbr != nbr)
			do_ra(a, b, f);
	else
		while ((*a)->nbr != nbr)
			do_rra(a, b, f);
}

void	put_at_top_b(t_stack **a, t_stack **b, int nbr, t_flags *f)
{
	int	med;

	if (get_size(*b) < 2 || (*b)->nbr == nbr)
		return ;
	med = get_size(*b) / 2;
	if (find_nbr_in_bottom(*b, nbr, med))
		while ((*b)->nbr != nbr)
			do_rb(a, b, f);
	else
		while ((*b)->nbr != nbr)
			do_rrb(a, b, f);
}
