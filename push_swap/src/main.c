/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:18:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:21:10 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*ft_add(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

static t_stack	*t_stack_a(char **argv, int argc)
{
	int		i;
	t_stack	*s;
	t_stack	*first;

	i = 1;
	s = NULL;
	first = ft_add(ft_atol(argv[i++]));
	first->next = s;
	s = first;
	while (i != argc)
	{
		s->next = ft_add(ft_atol(argv[i]));
		s = s->next;
		i++;
	}
	s->next = NULL;
	return (first);
}

static void	free_stack(t_stack **s)
{
	t_stack	*this;
	t_stack	*next;

	if (!s)
		return ;
	this = *s;
	while (this)
	{
		next = this->next;
		free(this);
		this = next;
	}
	*s = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check_args(argc, argv);
	a = t_stack_a(argv, argc);
	if (is_sorted(&a))
		return (0);;
	sort(argc, a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
