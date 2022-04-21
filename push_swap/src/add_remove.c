/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:08:02 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:17:05 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_add(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

void	ft_add_top(t_stack **s, t_stack *new)
{
	t_stack	*result;

	result = *s;
	if (!s)
		return ;
	if (!(*s))
		result = new;
	else
	{
		while ((*s)->next)
			*s = (*s)->next;
		(*s)->next = new;
	}
	*s = result;
}

void	ft_rm_top(t_stack **s)
{
	t_stack	*result;

	result = *s;
	if (!s || !(*s))
		return ;
	if (get_size(*s) == 1)
	{
		*s = NULL;
		return ;
	}
	while ((*s)->next->next)
		*s = (*s)->next;
	(*s)->next = NULL;
	*s = result;
}
