#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*last;
	int				nbr;
	struct s_stack	*next;
}	stack;

/* PROGRAM INIT */

int		main(int argc, char **argv);
void	check_args(int argc, char **argv);

/* MOVES */

void	do_pa(stack **a, stack **b);
void	do_pb(stack **a, stack **b);
void	do_sa(stack **s);
void	do_sb(stack **s);
void	do_ss(stack **a, stack **b);
void	do_ra(stack **s);
void	do_rb(stack **s);
void	do_rr(stack **a, stack **b);
void	do_ra(stack **s);
void	do_rra(stack **s);
void	do_rrb(stack **s);
void	do_rrr(stack **a, stack **b);

/* GET FUNCTIONS */

stack   *get_bottom(stack *s);
stack   *get_top(stack *s);
int 	get_size(stack *s);
int 	get_bigger(stack *s);
int		get_smaller(stack *s);

/* ADD & REMOVE */

stack *ft_add_bottom(stack **s, stack *new);
stack *ft_add_top(stack **s, stack *new);
stack *ft_rm(stack *s);

/* SORT */

void    sort_three(stack **a);
void    sort_small(stack **a, stack **b);
void    sort_medium(stack **a, stack **b);
void    sort_big(stack **a, stack **b);
int		is_sorted(stack *s);

/* SORT A */

int		handle_sort_a(stack **s, int div, int aux);
int		top(stack *s, int medium_pos, int first, int last);
int		bottom(stack *s, int medium_pos, int first, int last);
int		find_top(stack *s, int first, int last);
int		find_bottom(stack *s, int first, int last);

/* SORT B */

void	handle_sort_b(stack **s);
void	re_push(stack **s);
int 	top_b(stack *s, int n);
int 	bottom_b(stack *s, int n);

#endif

