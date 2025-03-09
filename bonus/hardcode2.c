/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:14:58 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/08 03:21:03 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dos(t_stack **stack_a)
{
	int	a;
	int	b;

	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	if (a > b)
		sa(stack_a);
}
