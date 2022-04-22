/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:05:19 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/01 17:25:47 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

/* STACK */

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_flags
{
	int		view;
	int		color;
	int		count;
}	t_flags;

/* PROGRAM INIT */

int			main(int argc, char **argv);
int			check_args(int argc, char **argv, t_flags **f);

/* MOVES */

void		do_pa(t_stack **a, t_stack **b, t_flags *f);
void		do_pb(t_stack **a, t_stack **b, t_flags *f);
void		do_sa(t_stack **a, t_stack **b, t_flags *f);
void		do_sb(t_stack **a, t_stack **b, t_flags *f);
void		do_ss(t_stack **a, t_stack **b, t_flags *f);
void		do_ra(t_stack **a, t_stack **b, t_flags *f);
void		do_rb(t_stack **a, t_stack **b, t_flags *f);
void		do_rr(t_stack **a, t_stack **b, t_flags *f);
void		do_rra(t_stack **a, t_stack **b, t_flags *f);
void		do_rrb(t_stack **a, t_stack **b, t_flags *f);
void		do_rrr(t_stack **a, t_stack **b, t_flags *f);

/* GET FUNCTIONS */

int			get_size(t_stack *s);
int			get_biggest(t_stack *s);
int			get_smallest(t_stack *s);

/* FIND FUNCTIONS */

int			find_range_in_stack(t_stack *s, int first, int last);
int			find_nbr_in_bottom(t_stack *s, int n, int med);
int			find_range_in_bottom(t_stack *s, int fst, int lst, int med);

/* ADD FUNCTION */

t_stack		*ft_add(int n);

/* SORT FUNCTIONS */

void		sort(int argc, t_stack *a, t_stack *b, t_flags *f);
void		sort_easy(t_stack **a, t_stack **b, t_flags *f);
void		sort_two_a(t_stack **a, t_stack **b, t_flags *f);
void		sort_two_b(t_stack **a, t_stack **b, t_flags *f);
void		sort_three_a(t_stack **a, t_stack **b, t_flags *f);
void		sort_three_b(t_stack **a, t_stack **b, t_flags *f);
void		sort_five(t_stack **a, t_stack **b, t_flags *f);
void		sort_hundreds(t_stack **a, t_stack **b, int div, t_flags *f);
int			is_sorted(t_stack **s);

/* PUT AT TOP FUNCTIONS */

void		put_range_top_a(t_stack **a, t_stack **b, int *v, t_flags *f);
void		put_at_top_a(t_stack **a, t_stack **b, int nbr, t_flags *f);
void		put_at_top_b(t_stack **a, t_stack **b, int nbr, t_flags *f);

/* PRINT STACKS FUNCTION */

void		print_stack_a_and_b(t_stack *a, t_stack *b, int first, t_flags *f);

#endif