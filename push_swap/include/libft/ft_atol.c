long ft_atol(char *str)
{
    long result;
    int sign;
    int i;

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
