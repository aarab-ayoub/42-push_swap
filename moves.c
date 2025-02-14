/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:05:39 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/15 19:05:40 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	move_swap(int *a, int *b)
{
	int	temp;

	temp = a;
	a = b;
	b = temp;
}

void	rotate(int **tab)
{
	int	i;
	int	big;

	i = 0;
	big = tab[0];
	while (tab[i])
	{
		if (big <= tab[i])
		{
			big = tab[i];
		}
		i++;
	}
}

void	rev_rotate(int **tab)
{
	int	i;
	int	big;

	i = 0;
	big = tab[ft_strlen(tab)];
	while (i < big)
	{
		if (big <= tab[i])
		{
			big = tab[i];
		}
		i++;
	}
}
