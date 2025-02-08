/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:31:39 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/08 13:43:30 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	a;

	i = 1;
	if (argc < 2)
	{
		write(1, "ERROR\n", 6);
	}
	else
	{
		while (argv[i])
		{
			if (!is_valid_int(argv[i]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			a = ft_atoi(argv[i]);
			ft_putnbr_fd(a, 1);
			write(1, "\n", 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
