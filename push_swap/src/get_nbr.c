/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:12:29 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:18:06 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_bottom(t_stack *s)
{
	if (s == NULL)
		return (NULL);
	while (s->last)
		s = s->last;
	return (s);
}

t_stack	*get_top(t_stack *s)
{
	if (s == NULL)
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

int	get_bigger(t_stack *s)
{
	int	i;

	i = s->nbr;
	while (s)
	{
		s = s->next;
		if (s && s->nbr > i)
			i = s->nbr;
	}
	return (i);
}

int	get_smaller(t_stack *s)
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
