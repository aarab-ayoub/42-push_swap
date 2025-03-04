/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:56:06 by ayoub             #+#    #+#             */
/*   Updated: 2025/03/04 16:13:03 by ayoub            ###   ########.fr       */
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

void update_indexes(t_stack *stack) 
{
    int index = 0;
    while (stack) {
        stack->index = index;
        index++;
        stack = stack->next;
    }
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
        closest = INT_MAX;
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

void final_rotate(t_stack **stackA) {
    t_stack *current = *stackA;
    int min_index = 0;
    int min_value = current->nbr;
    int index = 0;

    while (current) {
        if (current->nbr < min_value) {
            min_value = current->nbr;
            min_index = index;
        }
        current = current->next;
        index++;
    }

    if (min_index <= ft_lstsize(*stackA) / 2) {
        for (int i = 0; i < min_index; i++) {
            ra(stackA);
        }
    } else {
        for (int i = 0; i < ft_lstsize(*stackA) - min_index; i++) {
            rra(stackA);
        }
    }
}
