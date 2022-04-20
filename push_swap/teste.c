#include "./include/push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}



long long	ft_atol(const char *str)
{
	long long	result;
	int			sign;
	int			i;

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

static int	ft_malloc(int n, int count)
{
	if (n <= 0)
		return (count + 1);
	else
		return (count);
}

static char	*ft_strrev(char *str, int n)
{
	int		i;
	int		j;
	int		size;
	char	aux;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	j = size - 1;
	if (n < 0)
	{
		i++;
		size++;
	}
	while (i < size / 2)
	{
		aux = str[i];
		str[i] = str[j];
		str[j--] = aux;
		i++;
	}
	return (str);
}

static char	*ft_strnbr(char *str, int n)
{
	int		i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		aux;

	count = 0;
	aux = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (aux != 0)
	{
		aux = aux / 10;
		count++;
	}
	str = malloc(sizeof(char) * (ft_malloc(n, count) + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strnbr(str, n);
	str = ft_strrev(str, n);
	return (str);
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

int	find_range_in_bottom(t_stack *s, int fst, int lst, int med)
{
	int	i;

	i = 1;
	while (s && i <= med)
	{
		if (s->nbr >= fst && s->nbr <= lst)
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

void	put_range_at_top_a(t_stack **s, int fst, int lst)
{
	int	med;

	if (get_size(*s) < 2 || 
		(get_top(*s)->nbr >= fst && get_top(*s)->nbr <= lst))
		return ;
	med = get_size(*s) / 2;
	if (find_range_in_bottom(*s, fst, lst, med))
		while (!(get_top(*s)->nbr >= fst && get_top(*s)->nbr <= lst))
			do_ra(s);
	else
		while (!(get_top(*s)->nbr >= fst && get_top(*s)->nbr <= lst))
			do_rra(s);
}

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
    if (get_size(*b) == 3)
		sort_three_b(b);
    else
		sort_two_b(b);
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

void	sort_hundreds(t_stack **a, t_stack **b, int div)
{
	int	smallest;
	int	add;

	smallest = get_smallest(*a);
	add = get_biggest(*a) / div;
    while (smallest < get_biggest(*a))
    {
		while (find_range_in_stack(*a, smallest, smallest + add))
		{
			put_range_at_top_a(a, smallest, smallest + add);
        	do_pb(a, b);
		}
		smallest += add;
    }
	while (get_size(*a))
		do_pb(a, b);
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
		sort_hundreds(&a, &b, 5);
	else if (argc <= 501)
		sort_hundreds(&a, &b, 11);
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

void	print_stack_limit()
{
	ft_putstr_fd("-----------     -----------\n", 1);
	ft_putstr_fd("     A               B     \n\n", 1);
}

void	spaces(int total)
{
	int	i;

	i = -1;
	while (++i != total)
		ft_putchar_fd(' ', 1);
}

void	print_a_bigger(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;	
	if (a->next)
	{
		if (b)
			print_stack_a_and_b(a->next, b->next, 0);
		else
			print_stack_a_and_b(a->next, b, 0);
		spaces(11 - ft_strlen(ft_itoa(a->nbr)));
		ft_putnbr_fd(a->nbr, 1);
		if (b)
		{
			spaces(16 - ft_strlen(ft_itoa(b->nbr)));
			ft_putnbr_fd(b->nbr, 1);
		}
		ft_putchar_fd('\n', 1);
	}
	else
	{
		spaces(11 - ft_strlen(ft_itoa(a->nbr)));
		ft_putnbr_fd(a->nbr, 1);
		if (b)
		{
			spaces(16 - ft_strlen(ft_itoa(b->nbr)));
			ft_putnbr_fd(b->nbr, 1);
		}
		ft_putchar_fd('\n', 1);
	}
}

void	print_b_bigger(t_stack *a, t_stack *b)
{
	if (!a && !b)
		return ;	
	if (b->next)
	{
		if (a)
		{
			print_stack_a_and_b(a->next, b->next, 0);
			spaces(11 - ft_strlen(ft_itoa(a->nbr)));
			ft_putnbr_fd(a->nbr, 1);
		}
		else
		{
			print_stack_a_and_b(a, b->next, 0);
			spaces(11);
		}
		spaces(16 - ft_strlen(ft_itoa(b->nbr)));
		ft_putnbr_fd(b->nbr, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		if (a)
		{
			ft_putnbr_fd(a->nbr, 1);
			spaces(11 - ft_strlen(ft_itoa(b->nbr)));
		}
		else
			spaces(11);
		spaces(16 - ft_strlen(ft_itoa(b->nbr)));
		ft_putnbr_fd(b->nbr, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	print_stack_a_and_b(t_stack *a, t_stack *b, int first)
{
	if (!a && !b)
		return ;
	if (first)
		ft_putstr_fd("\nStacks:\n\n", 1);
	if (get_size(a) >= get_size(b))
		print_a_bigger(a, b);
	else
		print_b_bigger(a, b);
	if (first)
		print_stack_limit(a, b);
}

// =========================================================

static int  sort_last_two(t_stack **a)
{
	t_stack	*aux;

	aux = *a;
	while (aux->next->next)
	{
		if (aux->next && aux->next->nbr > aux->nbr)
			return (0);
		aux = aux->next;
	}
	return (1);
}

static int  top_bigger_than_bottom(t_stack *bott, t_stack *top)
{
    t_stack  *first_top;

	first_top = top;
    while (bott != first_top)
    {
        top = first_top;
        while (top)
        {
            if (top->nbr < bott->nbr)
                return (0);
            top = top->next;
        }
        bott = bott->next;
    }
    return (1);
}

static int  is_semi_sorted_top(t_stack **a, t_stack *s)
{
	if (!top_bigger_than_bottom(*a, s))
	{
    	return (0);
	}
	while (s->next)
	{
		if (s->next->nbr > s->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}

static int  is_semi_sorted_bottom(t_stack **a)
{
    t_stack	*aux;

	aux = *a;
	while (aux->next)
	{
		if (aux->next->nbr > aux->nbr)
			return (is_semi_sorted_top(a, aux->next));
		aux = aux->next;
	}
	return (0);
}

void    sort_easy(t_stack **a)
{
	if (is_semi_sorted_bottom(a))
        return (put_at_top_a(a, get_smallest(*a)));
    if (sort_last_two(a))
        return (do_sa(a));
    if (is_sorted(&(*a)->next))
        return (do_ra(a));
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
		sort_easy(&a);
	if (!is_sorted(&a))
		sort(argc, a, b);
	free_stack(&a);
	return (0);
}
