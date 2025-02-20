/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:41:57 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/20 12:42:15 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	main(void)
{
	t_stack	*stack_a;
	int		len;
	int		min;
	t_stack	*content;

	stack_a = malloc(sizeof(t_stack));
	stack_a->nbr = 1;
	stack_a->next = malloc(sizeof(t_stack));
	stack_a->next->nbr = 2;
	stack_a->next->next = malloc(sizeof(t_stack));
	stack_a->next->next->nbr = 3;
	stack_a->next->next->next = malloc(sizeof(t_stack));
	stack_a->next->next->next->nbr = 0;
	stack_a->next->next->next->next = malloc(sizeof(t_stack));
	stack_a->next->next->next->next->nbr = 4;
	len = ft_lstsize(stack_a);
	min = stack_a->nbr;
	content = stack_a;
	while (content->next && len > 2)
	{
		if (content->nbr < min)
		{
			min = content->nbr;
		}
		content = content->next;
	}
	printf("%d", min);
	return (0);
}
