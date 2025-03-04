/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:31:39 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/04 16:14:42 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*head;

	if (!stack)
		return ;
	while (stack->next)
	{
		head = stack;
		stack = stack->next;
		free(head);
	}
	free(stack);
}
t_stack	*create_stack(int *arr, int len)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	i = 0;
	stack = NULL;
	while (i < len)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
		{
			free_stack(stack);
			return (NULL);
		}
		new->nbr = arr[len - 1 - i];
		new->index = i;
		new->next = stack;
		stack = new;
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		arr_size;
	t_stack	*stackA;
	t_stack	*stackB;
	int		len;

	stackB = NULL;
	if (argc < 2)
		return (1);
	arr_size = count_numbers(argc, argv);
	arr = malloc(arr_size * sizeof(int));
	if (!arr)
		return (1);
	if (!parse_numbers(argc, argv, arr))
	{
		free(arr);
		return (1);
	}
	// int j = 0;
	// while (j < arr_size)
	// {
	//     printf("arr[%d] = %d\n", j, arr[j]);
	//     j++;
	// }
	stackA = create_stack(arr, arr_size);
	len = ft_lstsize(stackA);
	if (len == 0)
	{
		free(arr);
		free_stack(stackA);
		return (1);
	}
	if (!is_sorted(&stackA))
	{
		if (len < 3)
			sort_dos(&stackA);
		else if (len < 4)
			sort_trois(&stackA);
		else if (len == 5)
			sort_cinq(&stackA, &stackB);
		else
			sort_big(&stackA, &stackB);
	}
	// else
	// {
	//     sort_big(&stackA, &stackB);
	// // }
	// print_stack(stackA);
	free(arr);
	free_stack(stackA);
	return (0);
}
