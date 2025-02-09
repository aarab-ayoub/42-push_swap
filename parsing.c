/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:31:39 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/09 13:43:29 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(int *tab, int nbr, int pos)
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

static int	is_valid_int(const char *str)
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

int	main(int argc, char **argv)
{
	int	i;
	int	*arr;

	if (argc < 2)
		exit(1);
	arr = malloc((argc - 1) * sizeof(int));
	if (!arr)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		arr[i - 1] = ft_atoi(argv[i]);
		if (is_duplicate(arr, arr[i - 1], i - 1))
		{
			write(2, "Error\n", 6);
			free(arr);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_putnbr_fd(arr[i], 2);
		write(1, "\n", 1);
		i++;
	}
	free(arr);
	return (0);
}
