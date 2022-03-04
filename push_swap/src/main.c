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

static t_stack	*ft_add(int n, t_stack *last)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->last = last;
	new->nbr = n;
	new->next = NULL;
	return (new);
}

static t_stack	*t_stack_a(char **argv, int argc)
{
	int		i;
	t_stack	*last;
	t_stack	*s;
	t_stack *first;

	i = 1;
	last = NULL;
	s = NULL;
	first = ft_add(ft_atol(argv[i++]), last);
	first->next = s;
	s = first;
	last = s;
	while (i != argc)
	{
		s->next = ft_add(ft_atol(argv[i]), last);
		last = s;
		s = s->next;
		i++;
	}
	s->next = NULL;
	return (first);
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
		exit(0);
	if (argc <= 4)
		sort_three(&a);
	else if (argc <= 6)
		sort_small(&a, &b);
	else if (argc <= 101)
		sort_medium(&a, &b);
	else if (argc <= 501)
		sort_big(&a, &b);
	free(a);
	free(b);
	return (0);
}
