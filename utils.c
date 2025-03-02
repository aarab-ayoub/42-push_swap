/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:56:06 by ayoub             #+#    #+#             */
/*   Updated: 2025/03/04 02:16:43 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_sorted(t_stack **stack_a)
{
	t_stack	*current;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (1);
	current = *stack_a;
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}
int find_target(t_stack *stackA, int value) {
    t_stack *current = stackA;
    int target = INT_MAX;
    int closest = INT_MAX;

    while (current) {
        if (current->nbr > value && current->nbr < closest) {
            closest = current->nbr;
            target = current->nbr;
        }
        current = current->next;
    }

    if (target == INT_MAX) {
        current = stackA;
        while (current) {
            if (current->nbr < closest) {
                closest = current->nbr;
                target = current->nbr;
            }
            current = current->next;
        }
    }

    return target;
}

