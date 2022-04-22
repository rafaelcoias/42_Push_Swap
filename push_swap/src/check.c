/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:21:27 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:17:20 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	send_message(void)
{	
	write(1, "\033[1;31mError\n[0m", 13);
	exit(0);
}

static int	check_arg(char *arg)
{
	int	min;
	int	max;

	min = -2147483648;
	max = 2147483647;
	if (!ft_strcmp(arg, "0"))
		return (1);
	if (ft_atol(arg) == 0 || ft_atol(arg) > max || ft_atol(arg) < min)
		return (0);
	return (1);
}

static int	check_duplicate(int argc, char **argv, int i, int j)
{
	while (i != argc)
	{
		if (i != j && ft_atol(argv[i]) == ft_atol(argv[j]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_flags(int argc, char **argv, int i, t_flags **f)
{
	if (argc > 1 && (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-c")))
	{
		if (!ft_strcmp(argv[1], "-v"))
			(*f)->view = 1;
		if (!ft_strcmp(argv[1], "-c"))
			(*f)->color = 1;
		i++;
	}
	if (argc > 2 && (!ft_strcmp(argv[2], "-v") || !ft_strcmp(argv[2], "-c")))
	{
		if (!ft_strcmp(argv[2], "-v"))
			(*f)->view = 1;
		if (!ft_strcmp(argv[2], "-c"))
			(*f)->color = 1;
		i++;
	}
	return (i);
}

int	check_args(int argc, char **argv, t_flags **f)
{
	int	fst;
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	if (argv[0][2] == 'c')
		i = check_flags(argc, argv, i, f);
	fst = i;
	while (i != argc)
	{
		if (!check_arg(argv[i]))
			send_message();
		if (!check_duplicate(argc, argv, fst, i))
			send_message();
		i++;
	}
	return (fst);
}
