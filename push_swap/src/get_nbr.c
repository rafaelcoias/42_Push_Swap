/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:12:29 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:17:56 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_top(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int	get_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	get_biggest(t_stack *s)
{
	int	i;

	if (!s)
		return (0);
	i = s->nbr;
	while (s->next)
	{
		s = s->next;
		if (s->nbr > i)
			i = s->nbr;
	}
	return (i);
}

int	get_smallest(t_stack *s)
{
	int	i;

	i = s->nbr;
	while (s)
	{
		s = s->next;
		if (s && s->nbr < i)
			i = s->nbr;
	}
	return (i);
}

int	find(t_stack *s, int fst, int lst)
{
	if (!s)
		return (0);
	while (s->next)
	{
		if (s->nbr >= fst && s->nbr <= lst)
			return (1);
		s = s->next;
	}
	return (0);
}
