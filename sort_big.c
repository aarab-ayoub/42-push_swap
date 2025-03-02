/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:11:07 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/04 03:15:19 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_stack **stackA, t_stack **stackB)
{
	int	len;
	int	i;

	len = ft_lstsize(*stackA);
	i = 0;
	while (i < len)
	{
		pb(stackA, stackB);
		i++;
	}
}
void final_rotate(t_stack **stackA) {
    t_stack *current = *stackA;
    int min_pos = 0;
    int min_value = current->nbr;

    while (current) {
        if (current->nbr < min_value) {
            min_value = current->nbr;
            min_pos = current->index;
        }
        current = current->next;
    }

    if (min_pos <= ft_lstsize(*stackA) / 2) {
        for (int i = 0; i < min_pos; i++)
            ra(stackA);
    } else {
        for (int i = 0; i < ft_lstsize(*stackA) - min_pos; i++)
            rra(stackA);
    }
}

void sort_big(t_stack **stackA, t_stack **stackB) {
    t_cost cheapest;

    push_all_to_b(stackA, stackB);
    sort_trois(stackA);

    while (*stackB) {
        find_cheapest(*stackA, *stackB, &cheapest);
        apply_moves(stackA, stackB, &cheapest);
    }

    final_rotate(stackA);
}

