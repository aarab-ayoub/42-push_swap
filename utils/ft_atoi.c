#include "../push_swap.h"

int ft_atoi(const char *str)
{
	size_t i = 0;
	int sign = 1;
	unsigned long long result = 0;

	while (is_delimiter(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && result > (unsigned long long)INT_MAX + 1))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (int)(sign * result);
}
