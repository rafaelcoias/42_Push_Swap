#include "../include/push_swap.h"

static void send_message()
{
    write(1, "Error\n", 6);
    exit(0);
}

static int check_arg(char *arg)
{
    if (arg == "0")
        return (1);
    if (ft_atol(arg) == 0 || ft_atol(arg) > 2147483647 || ft_atol(arg) < -2147483648)
        return (0);
    return (1);
}

static int check_duplicate(int argc, char **argv, int j)
{
    int i;
    int n;

    i = 1;
    n = ft_atol(argv[j]);
    while (i != argc)
    {
        if (i != j && argv[i] == argv[j])
            return (0);
        i++;
    }
    return (1);
}

void check_args(int argc, char **argv)
{
    int i;

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