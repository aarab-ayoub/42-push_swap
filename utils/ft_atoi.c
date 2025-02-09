#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_delimiter(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		res = res * 10 + str[i++] - '0';
	}
	return (res * sign);
}
