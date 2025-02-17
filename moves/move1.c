/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:43:24 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/17 01:11:49 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack **stack_a , t_stack **stack_b)
{
	push(stack_a,stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_b , t_stack **stack_a)
{
	push(stack_b,stack_a);
	ft_putstr_fd("pa\n", 1);
}
