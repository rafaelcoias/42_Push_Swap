#include "./include/push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	ft_add_top(t_stack **s, t_stack *new)
{
	t_stack	*result;

	result = *s;
	if (!s)
		return ;
	if (!(*s))
		result = new;
	else
	{
		while ((*s)->next)
			*s = (*s)->next;
		(*s)->next = new;
	}
	*s = result;
}

void	ft_rm_top(t_stack **s)
{
	t_stack	*result;

	result = *s;
	if (!s || !(*s))
		return ;
	if (get_size(*s) == 1)
	{
		*s = NULL;
		return ;
	}
	while ((*s)->next->next)
		*s = (*s)->next;
	(*s)->next = NULL;
	*s = result;
}

// =========================================================

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
		if (i != j && ft_atol(argv[i]) == ft_atol(argv[j]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
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

// =========================================================

int	find_range_in_stack(t_stack *s, int first, int last)
{
	int	i;

	i = 1;
	while (s)
	{
		if (s->nbr >= first && s->nbr <= last)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}

int	find_nbr_in_bottom(t_stack *s, int n, int med)
{
	int	i;

	i = 1;
	while (s && i <= med)
	{
		if (s->nbr == n)
			return (i);
		i++;
		s = s->next;
	}
	return (0);
}

int	find_nbr_in_stack(t_stack *s, int nbr)
{
	if (!s)
		return (0);
	while (s->next)
	{
		if (s->nbr == nbr)
			return (1);
		s = s->next;
	}
	return (0);
}

int	find_smallest_in_range(int fst, int lst)
{
	int	min;

	min = fst;
	while (++fst != lst + 1)
		if (min < fst)
			min = fst;
	return (min);
}

// =========================================================

t_stack	*get_top(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int	get_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	get_biggest(t_stack *s)
{
	int	i;

	if (!s)
		return (0);
	i = s->nbr;
	while (s->next)
	{
		s = s->next;
		if (s->nbr > i)
			i = s->nbr;
	}
	return (i);
}

int	get_smallest(t_stack *s)
{
	int	i;

	i = s->nbr;
	while (s)
	{
		s = s->next;
		if (s && s->nbr < i)
			i = s->nbr;
	}
	return (i);
}

// =========================================================

void	push(t_stack **a, t_stack **b)
{
	if (!b || get_size(*b) == 0)
		return ;
	ft_add_top(a, get_top(*b));
	ft_rm_top(b);
}

void	do_pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	do_pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

// =========================================================

void	put_at_top_a(t_stack **s, int nbr)
{
	int	med;

	if (get_size(*s) < 2 || get_top(*s)->nbr == nbr)
		return ;
	med = get_size(*s) / 2;
	if (find_nbr_in_bottom(*s, nbr, med))
		while (get_top(*s)->nbr != nbr)
			do_ra(s);
	else
		while (get_top(*s)->nbr != nbr)
			do_rra(s);
}

void	put_at_top_b(t_stack **s, int nbr)
{
	int	med;

	if (get_size(*s) < 2 || get_top(*s)->nbr == nbr)
		return ;
	med = get_size(*s) / 2;
	if (find_nbr_in_bottom(*s, nbr, med))
		while (get_top(*s)->nbr != nbr)
			do_rb(s);
	else
		while (get_top(*s)->nbr != nbr)
			do_rrb(s);
}

// =========================================================

static void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*result;

	first = *s;
	result = (*s)->next;
	while ((*s)->next)
		*s = (*s)->next;
	(*s)->next = first;
	*s = result;
	first->next = NULL;
}

void	do_ra(t_stack **s)
{
	rotate(s);
	write(1, "ra\n", 3);
}

void	do_rb(t_stack **s)
{
	rotate(s);
	write(1, "rb\n", 3);
}

void	do_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

// =========================================================

static void	rv_rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	first = *s;
	tmp = *s;
	while (tmp -> next)
		tmp = tmp -> next;
	last = tmp;
	*s = last;
	last -> next = first;
	while (tmp -> next != last)
		tmp = tmp -> next;
	tmp->next = NULL;
}

void	do_rra(t_stack **s)
{
	rv_rotate(s);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **s)
{
	rv_rotate(s);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **a, t_stack **b)
{
	rv_rotate(a);
	rv_rotate(b);
	write(1, "rrr\n", 4);
}

// =========================================================

static void	swap(t_stack **s)
{
	int		aux;
	t_stack	*result;

	result = *s;
	while ((*s)->next->next)
		*s = (*s)->next;
	aux = (*s)->nbr;
	(*s)->nbr = (*s)->next->nbr;
	(*s)->next->nbr = aux;
	*s = result;
}

void	do_sa(t_stack **s)
{
	swap(s);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **s)
{
	swap(s);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

// =========================================================

void	sort_five(t_stack **a, t_stack **b)
{
	while (get_size(*a) > 3)
		do_pb(a, b);
	sort_three(a);
    if (get_size(*b) != 3)
	    sort_two_b(b);
    else 
        sort_three_b(b);
	while (get_size(*b) > 0)
	{
		if (get_biggest(*a) < get_top(*b)->nbr)
		{
			do_pa(a, b);
			do_rra(a);
			continue ;
		}
		if (get_top(*b)->nbr > get_top(*a)->nbr)
			do_rra(a);
		else
			do_pa(a, b);
    }
	put_at_top_a(a, get_smallest(*a));
}

// =========================================================

void	sort_hundreds(t_stack **a, t_stack **b)
{
    while (get_size(*a) > 3)
    {
        put_at_top_a(a, get_smallest(*a));
        do_pb(a, b);
    }
	sort_three(a);
	while (get_size(*b))
	{
		put_at_top_b(b, get_biggest(*b));
		do_pa(a, b);
	}
}

// =========================================================

void	sort_three(t_stack **s)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!(*s))
		return ;
	a = *s;
	b = a->next;
	c = b->next;
	while (!is_sorted(s))
	{
		if ((a->nbr > b->nbr && a->nbr > c->nbr)
			|| (a->nbr < b->nbr && a->nbr < c->nbr && b->nbr < c->nbr)
			|| (c->nbr < b->nbr && c->nbr < a->nbr))
			do_sa(s);
		else if (c->nbr > b->nbr
			&& c->nbr > a->nbr
			&& b->nbr < a->nbr)
			do_rra(s);
		else if (a->nbr < b->nbr && a->nbr < c->nbr)
			do_ra(s);
	}
}

void	sort_three_b(t_stack **s)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!(*s))
		return ;
	a = *s;
	b = a->next;
	c = b->next;
	while (!is_sorted(s))
	{
		if ((a->nbr > b->nbr && a->nbr > c->nbr)
			|| (a->nbr < b->nbr && a->nbr < c->nbr && b->nbr < c->nbr)
			|| (c->nbr < b->nbr && c->nbr < a->nbr))
			do_sb(s);
		else if (c->nbr > b->nbr
			&& c->nbr > a->nbr
			&& b->nbr < a->nbr)
			do_rrb(s);
		else if (a->nbr < b->nbr && a->nbr < c->nbr)
			do_rb(s);
	}
}

// =========================================================

void	sort_two_a(t_stack **a)
{
	if (!is_sorted(a))
		do_sa(a);
	return ;
}

void	sort_two_b(t_stack **b)
{
	if (!is_sorted(b))
		do_sb(b);
	return ;
}

// =========================================================

void	sort(int argc, t_stack *a, t_stack *b)
{
	//print_stack_a_and_b(a, b, 1);
	//ft_putstr_fd("\nOperations:\n\n", 1);
	if (argc == 3)
		sort_two_a(&a);
	else if (argc == 4)
		sort_three(&a);
	else if (argc <= 7)
		sort_five(&a, &b);
	else if (argc <= 101)
		sort_hundreds(&a, &b);
	else if (argc <= 501)
		sort_hundreds(&a, &b);
	//print_stack_a_and_b(a, b, 1);
}

int	is_sorted(t_stack **s)
{
	t_stack	*aux;

	aux = *s;
	while (aux)
	{
		if (aux->next && aux->next->nbr > aux->nbr)
			return (0);
		aux = aux->next;
	}
	return (1);
}

// =========================================================

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
	if (!is_sorted(&a))
		sort(argc, a, b);
	free_stack(&a);
	return (0);
}
