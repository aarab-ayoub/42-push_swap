#include "push_swap.h"

int is_duplicate(int *tab, int nbr, int pos)
{
	int i = 0;
	while (i < pos)
	{
		if (tab[i] == nbr)
			return 1;
		i++;
	}
	return 0;
}

int is_valid_int(const char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

void	free_split(char **split)
{
	int i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_numbers(int *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		ft_putnbr_fd(arr[i], 2);
		write(2, "\n", 1);
		i++;
	}
}

int count_split_args(char **split)
{
	int i = 0;
	int count = 0;
	while (split[i])
	{
		count++;
		i++;
	}
	return count;
}

