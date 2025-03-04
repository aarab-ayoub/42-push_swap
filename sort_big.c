/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:11:07 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/04 16:14:57 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_stack **stackA, t_stack **stackB)
{
	int	len;
	int	i;

	len = ft_lstsize(*stackA);
	i = 0;
	while (i < len - 3)
	{
		pb(stackA, stackB);
		i++;
	}
    // printf("pushed all to b\n");
}

void sort_big(t_stack **stackA, t_stack **stackB) {
    t_cost cheapest;

    push_all_to_b(stackA, stackB);
    sort_trois(stackA);
	// printf("sorted 3\n");
	
    while (*stackB) {
        find_cheapest(*stackA, *stackB, &cheapest);
        apply_moves(stackA, stackB, &cheapest);
		// printf("applied moves\n");
    }

    final_rotate(stackA);
	// printf("final rotated\n");
}

