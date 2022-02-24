#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	struct stack	*last;
	int				nbr;
	struct stack	*next;
}	stack;

void	check_args(int argc, char **argv);

void	do_pa(stack **a, stack **b);
void	do_pb(stack **a, stack **b);
void	do_sa(stack **s);
void	do_sb(stack **s);
void	do_ss(stack **a, stack **b);
void	do_ra(stack **s);
void	do_rb(stack **s);
void	do_rr(stack **a, stack **b);
void	do_ra(stack **s);
void	do_rrb(stack **s);
void	do_rrr(stack **a, stack **b);

void    sort_three(stack **a, stack **b);
void    sort_small(stack **a, stack **b);
void    sort_medium(stack **a, stack **b);
void    sort_big(stack **a, stack **b);
int		is_sorted(stack **a);

#endif

