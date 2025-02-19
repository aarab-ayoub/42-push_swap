/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:13:19 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/19 21:49:38 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_trois(t_stack **stack_a)
{
    int a = (*stack_a)->nbr;
    int b = (*stack_a)->next->nbr;
    int c = (*stack_a)->next->next->nbr;

    if (a < b && b < c)
        return;
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > c && c > b)
        ra(stack_a);
    else if (b > a && a > c)
        rra(stack_a);
    else if (b > c && c > a)
        sa(stack_a);
    else if (c > a && a > b)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (c > b && b > a)
    {
        sa(stack_a);
        rra(stack_a);
    }
}

// void		sort_cinq(t_stack **stack_a, t_stack **stack_b)
// {
// 	;
// }
