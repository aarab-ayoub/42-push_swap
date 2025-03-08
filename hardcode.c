/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:13:19 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/08 03:19:11 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_trois(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

static int	find_min(t_stack **stack)
{
	t_stack	*current;
	int		min;

	current = *stack;
	min = current->nbr;
	while (current)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

static void	traitement(int pos, t_stack **stack_a, t_stack **stack_b)
{
	if (pos == 0)
		pb(stack_a, stack_b);
	else if (pos == 1)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

static void	push_min_to_b(t_stack **stack_a, t_stack **stack_b, int min)
{
	t_stack	*current;
	int		pos;

	current = *stack_a;
	pos = 0;
	while (current && current->nbr != min)
	{
		current = current->next;
		pos++;
	}
	traitement(pos, stack_a, stack_b);
}

void	sort_cinq(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	second_min;
	int	len;

	len = ft_lstsize(*stack_a);
	if (len == 4 && !is_sorted(stack_a))
	{
		min = find_min(stack_a);
		push_min_to_b(stack_a, stack_b, min);
		sort_trois(stack_a);
		pa(stack_a, stack_b);
	}
	else if (len == 5 && !is_sorted(stack_a))
	{
		min = find_min(stack_a);
		push_min_to_b(stack_a, stack_b, min);
		second_min = find_min(stack_a);
		push_min_to_b(stack_a, stack_b, second_min);
		sort_trois(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
