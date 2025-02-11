/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:49 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/11 13:36:22 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int *tab, int nbr, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (tab[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_int(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_numbers(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(arr[i], 2);
		write(2, "\n", 1);
		i++;
	}
}

int	count_split_args(char **split)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (split[i])
	{
		count++;
		i++;
	}
	return (count);
}
