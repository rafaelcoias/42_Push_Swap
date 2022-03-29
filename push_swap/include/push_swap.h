/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:05:19 by rade-sar          #+#    #+#             */
/*   Updated: 2022/03/04 16:07:56 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

/* PROGRAM INIT */

int		main(int argc, char **argv);
void	check_args(int argc, char **argv);

/* MOVES */

void	do_pa(t_stack **a, t_stack **b);
void	do_pb(t_stack **a, t_stack **b);
void	do_sa(t_stack **s);
void	do_sb(t_stack **s);
void	do_ss(t_stack **a, t_stack **b);
void	do_ra(t_stack **s);
void	do_rb(t_stack **s);
void	do_rr(t_stack **a, t_stack **b);
void	do_ra(t_stack **s);
void	do_rra(t_stack **s);
void	do_rrb(t_stack **s);
void	do_rrr(t_stack **a, t_stack **b);

/* GET FUNCTIONS */

t_stack	*get_bottom(t_stack *s);
t_stack	*get_top(t_stack *s);
int		get_size(t_stack *s);
int		get_biggest(t_stack *s);
int		get_smallest(t_stack *s);

/* ADD & REMOVE */

void	ft_add_top(t_stack **s, t_stack *new);
void	ft_rm_top(t_stack **s);

/* SORT */

void    sort(int argc, t_stack *a, t_stack *b);
void	sort_two_a(t_stack **a);
void	sort_two_b(t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b);
int		is_sorted(t_stack **s);

/* SORT A */

int		handle_sort_a(t_stack **s, int div, int aux);
int		top(t_stack *s, int medium_pos, int first, int last);
int		bottom(t_stack *s, int medium_pos, int first, int last);
int		find_top(t_stack *s, int first, int last);
int		find_bottom(t_stack *s, int first, int last);

/* SORT B */

void	handle_sort_b(t_stack **s);
void	re_push(t_stack **s);
int		top_b(t_stack *s, int n);
int		bottom_b(t_stack *s, int n);

/* PRINT STACK */

void	print_stack(t_stack *s, int first);

#endif
