/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:21:27 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 15:25:50 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	send_message(void)
{	
	write(1, "Error\n", 6);
	exit(0);
}

static int	check_arg(char *arg)
{
	int	max;
	int	min;

	max = 2147483647;
	min = -2147483648;
	if (arg[0] == '0')
		return (1);
	if (ft_atol(arg) == 0 || ft_atol(arg) > max || ft_atol(arg) < min)
		return (0);
	return (1);
}


static int	check_duplicate(int argc, char **argv, int j)
{
	int	i;

	i = 1;
	while (i != argc)
	{
		if (i != j && argv[i] == argv[j])
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 3)
		exit(0);
	while (i != argc)
	{
		if (!check_arg(argv[i]))
			send_message();
		if (!check_duplicate(argc, argv, i))
			send_message();
		i++;
	}
}
