#include "./include/push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_add_top(t_stack **s, t_stack *new)
{
	t_stack *result;

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

void	sort_two(t_stack **a)
{
	if (!is_sorted(a))
		do_sa(a);
	return ;
}

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

void	ft_rm_top(t_stack **s)
{
	t_stack *result;

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

int	top_b(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->nbr == n)
			return (i);
		i++;
		//iterar s
	}
	return (i);
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

void	rv_rotate(t_stack **s)
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

void	rotate(t_stack **s)
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

void	swap(t_stack **s)
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

int	get_bigger(t_stack *s)
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

void	sort_two_b(t_stack **b)
{
	if (!is_sorted(b))
		do_sb(b);
	return ;
}

void	sort_a_rotations(t_stack **a)
{
	t_stack	*aux;
	int		bigger;
	int		i;
	int		med;

	aux = *a;
	bigger = get_bigger(*a);
	i = 0;
	med = (get_size(*a) / 2) + 0.5;
	while (i <= med && aux->next)
	{
		if (aux->nbr == bigger) 
		{
			while (!is_sorted(a))
				do_ra(a);
			return ;
		}
		aux = aux->next;
		i++;
	}
	while (!is_sorted(a))
		do_rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (get_size(*a) > 3)
		do_pb(a, b);
	sort_three(a);
	sort_two_b(b);
	while (get_size(*b) > 0)
	{
		if (get_bigger(*a) < get_top(*b)->nbr)
		{
			do_pa(a, b);
			do_rra(a);
			continue ;
		}
		if (get_top(*b)->nbr > get_top(*a)->nbr)
			do_rra(a);
		else
		{
			do_pa(a, b);
			if (get_top(*b) && get_bigger(*a) < get_top(*b)->nbr)
				sort_a_rotations(a);
		}
	}
	sort_a_rotations(a);
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

t_stack	*get_top(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
}

static void	ft_print_special(int fd)
{
	write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n != -2147483648)
	{
		if (n < 0)
		{
			n = n * (-1);
			ft_putchar_fd('-', fd);
		}
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
	else
		ft_print_special(fd);
}

void	print_stack(t_stack *s, int first)
{
	if (!s)
		return ;
	if (first)
		ft_putstr_fd("\nStack:\n\n", 1);
	if (s->next)
	{
		print_stack(s->next, 0);
		ft_putnbr_fd(s->nbr, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putnbr_fd(s->nbr, 1);
		ft_putchar_fd('\n', 1);
	}
	if (first)
		ft_putstr_fd("-\na\n", 1);
}

t_stack	*ft_add(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = n;
	new->next = NULL;
	return (new);
}

t_stack	*t_stack_a(char **argv, int argc)
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

int main(int argc, char **argv)
{
    t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = t_stack_a(argv, argc);
	print_stack(a, 1);
	ft_putstr_fd("\nOperations:\n\n", 1);
	if (argc == 3)
		sort_two(&a);
	else if (argc == 4)
		sort_three(&a);
	else if (argc <= 6)
		sort_five(&a, &b);
	print_stack(a, 1);
	return (0);
}