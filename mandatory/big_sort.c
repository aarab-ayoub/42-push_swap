/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:18:00 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/08 03:22:26 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_stack *stack)
{
	t_stack	*curr;
	int		max_idx;
	int		pos;
	int		i;

	curr = stack;
	max_idx = curr->index;
	pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->index > max_idx)
		{
			max_idx = curr->index;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

static void	push_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	min;
	int	max;

	size = ft_lstsize(*a);
	min = 0;
	max = 0.05 * size + 10;
	while (*a)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			pb(a, b);
			min++;
			max++;
		}
		else if ((*a)->index < min)
		{
			pb(a, b);
			rb(b);
			min++;
			max++;
		}
		else
			ra(a);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		size = ft_lstsize(*b) - 1;
		pos = get_max_pos(*b);
		if ((*b)->index == size)
			pa(a, b);
		else if (pos <= size / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	assign_indexes(*a);
	push_to_b(a, b);
	push_back_to_a(a, b);
}
