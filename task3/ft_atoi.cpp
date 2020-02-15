//
// Created by Earl Leonarda on 15/02/2020.
//

long long	ft_atoi(const char *str)
{
	long long	res;
	long long	sign;

	sign = 1;
	res = 0;
	if (*str == ' ' || *str == '+' || *str == '-' ||
		(*str >= 48 && *str <= 57) || (*str >= 9 && *str <= 13))
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (*str == '+' || (*str == '-' && (sign *= -1)))
			str++;
		while (*str >= 48 && *str <= 57)
		{
			res = res * 10 + *str - '0';
			str++;
		}
		return (res * sign);
	}
	return (0);
}
