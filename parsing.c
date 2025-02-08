/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:31:39 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/07 19:17:13 by ayaarab          ###   ########.fr       */
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
		write(1, "\n", 1);
	}
	else
	{
		while (argv[i])
		{
			a = ft_atoi(argv[i]);
			ft_putnbr(a);
			write(1, "\n", 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
