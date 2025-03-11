/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:56:06 by ayoub             #+#    #+#             */
/*   Updated: 2025/03/11 19:54:08 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	update_indexes(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*comp;
	int		idx;

	curr = stack;
	while (curr)
	{
		idx = 0;
		comp = stack;
		while (comp)
		{
			if (curr->nbr > comp->nbr)
				idx++;
			comp = comp->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
}
