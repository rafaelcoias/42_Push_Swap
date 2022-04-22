/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:18:22 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:19:51 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*t_stack_a(char **argv, int argc, int fst)
{
	t_stack	*s;
	t_stack	*first;

	s = NULL;
	first = ft_add(ft_atol(argv[fst++]));
	first->next = s;
	s = first;
	while (fst != argc)
	{
		s->next = ft_add(ft_atol(argv[fst]));
		s = s->next;
		fst++;
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

static void	checker(int argc, t_flags *f)
{
	ft_putstr_fd("\nNumber of moves : ", 1);
	ft_putnbr_fd(f->count, 1);
	ft_putchar_fd('\n', 1);
	if (argc <= 3 && f->count < 3)
		ft_putstr_fd("\033[0;32mOK\033[0m\n", 1);
	else if (argc <= 5 && f->count < 13)
		ft_putstr_fd("\033[0;32mOK\033[0m\n", 1);
	else if (argc <= 100 && f->count < 900)
		ft_putstr_fd("\033[0;32mGOOD\033[0m\n", 1);
	else if (argc <= 100 && f->count < 1100)
		ft_putstr_fd("\033[0;32mOK\033[0m\n", 1);
	else if (argc <= 500 && f->count < 7000)
		ft_putstr_fd("\033[0;32mGOOD\033[0m\n", 1);
	else if (argc <= 500 && f->count < 10000)
		ft_putstr_fd("\033[0;32mOK\033[0m\n", 1);
	else
		ft_putstr_fd("\033[0;31mKO\033[0m\n", 1);
	ft_putchar_fd('\n', 1);
}

static t_flags	*init_flags(void)
{
	t_flags	*new;

	new = malloc(sizeof(t_flags));
	if (!new)
		return (NULL);
	new->view = 0;
	new->color = 0;
	new->count = 0;
	return (new);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	*f;
	int		fst;

	a = NULL;
	b = NULL;
	f = init_flags();
	fst = 1;
	if (argv[0][2] == 'c')
		fst = check_args(argc, argv, &f);
	else
		check_args(argc, argv, &f);
	a = t_stack_a(argv, argc, fst);
	if (f->view)
		print_stack_a_and_b(a, b, 1, f);
	if (!is_sorted(&a))
		sort_easy(&a, &b, f);
	if (!is_sorted(&a))
		sort(argc - fst, a, b, f);
	free_stack(&a);
	if (argv[0][2] == 'c')
		checker(argc - fst, f);
	free(f);
	return (0);
}
