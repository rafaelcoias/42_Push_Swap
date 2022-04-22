/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:41:32 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/21 14:41:34 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_range_in_stack(t_stack *s, int first, int last)
{
	int	i;

	i = 1;
	while (s)
	{
		if (s->nbr >= first && s->nbr <= last)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}

int	find_nbr_in_bottom(t_stack *s, int n, int med)
{
	int	i;

	i = 1;
	while (s && i <= med)
	{
		if (s->nbr == n)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}

int	find_range_in_bottom(t_stack *s, int fst, int lst, int med)
{
	int	i;

	i = 1;
	while (s && i <= med)
	{
		if (s->nbr >= fst && s->nbr <= lst)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}
