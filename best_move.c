/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:31 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/04 03:09:09 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void cal_cost(t_stack *stackA, t_stack *stackB, t_cost *cost)
{
    cost->cost_a = 0;
    cost->cost_b = 0;
    cost->total_cost = 0;
    cost->target = 0;
    cost->target = find_target(stackA, stackB->nbr);
    t_stack *current = stackA;
    while (current && current->nbr != cost->target)
        current = current->next;
    if (current) {
        cost->cost_a = current->index;
        if (cost->cost_a > ft_lstsize(stackA) / 2)
            cost->cost_a = ft_lstsize(stackA) - cost->cost_a;
    }
    cost->cost_b = stackB->index;
    if (cost->cost_b > ft_lstsize(stackB) / 2)
        cost->cost_b = ft_lstsize(stackB) - cost->cost_b;
    cost->total_cost = cost->cost_a + cost->cost_b;
}

void find_cheapest(t_stack *stackA, t_stack *stackB, t_cost *cheapest) {
    t_cost current_cost;
    t_stack *current = stackB;

    cal_cost(stackA, current, &current_cost);
    *cheapest = current_cost;

    while (current) {
        cal_cost(stackA, current, &current_cost);
        if (current_cost.total_cost < cheapest->total_cost) {
            *cheapest = current_cost;
        }
        current = current->next;
    }
}

void optimize_rotations(t_stack **stackA, t_stack **stackB, t_cost *cost)
{
    if (cost->cost_a > 0 && cost->cost_b > 0 && cost->cost_a <= ft_lstsize(*stackA) / 2 && cost->cost_b <= ft_lstsize(*stackB) / 2) {
        int min_rotations = (cost->cost_a < cost->cost_b) ? cost->cost_a : cost->cost_b;
        for (int i = 0; i < min_rotations; i++)
            rr(stackA, stackB);
        cost->cost_a -= min_rotations;
        cost->cost_b -= min_rotations;
    }

    if (cost->cost_a > 0 && cost->cost_b > 0 && cost->cost_a > ft_lstsize(*stackA) / 2 && cost->cost_b > ft_lstsize(*stackB) / 2) {
        int min_rotations = (cost->cost_a < cost->cost_b) ? cost->cost_a : cost->cost_b;
        for (int i = 0; i < min_rotations; i++)
            rrr(stackA, stackB);
        cost->cost_a -= min_rotations;
        cost->cost_b -= min_rotations;
    }
}

void apply_moves(t_stack **stackA, t_stack **stackB, t_cost *cheapest) {
    t_stack *current;

    optimize_rotations(stackA, stackB, cheapest);

    current = *stackA;
    while (current && current->nbr != cheapest->target) {
        current = current->next;
    }
    if (current) {
        if (current->index <= ft_lstsize(*stackA) / 2) {
            for (int i = 0; i < current->index; i++)
                ra(stackA);
        } else {
            for (int i = 0; i < ft_lstsize(*stackA) - current->index; i++)
                rra(stackA);
        }
    }

    if (cheapest->cost_b <= ft_lstsize(*stackB) / 2) {
        for (int i = 0; i < cheapest->cost_b; i++)
            rb(stackB);
    } else {
        for (int i = 0; i < ft_lstsize(*stackB) - cheapest->cost_b; i++)
            rrb(stackB);
    }

    pa(stackA, stackB);
}
