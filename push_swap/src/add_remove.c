/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:08:02 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:11:59 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_add_bottom(t_stack **s, t_stack *new)
{
	if (!s)
		return (NULL);
	new->next = *s;
	*s = new;
	return (*s);
}

t_stack	*ft_add_top(t_stack **s, t_stack *new)
{
	t_stack	*aux;

	aux = NULL;
	if (!s)
		return (NULL);
	if (!(*s))
		*s = new;
	else
	{
		aux = get_top(*s);
		aux->next = new;
	}
	return (aux);
}

t_stack	*ft_rm(t_stack *s)
{
	if (s)
		free (s);
	s = NULL;
	return (s);
}
