/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:31:39 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/15 19:05:46 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		new->nbr = arr[i];
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

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	arr_size = count_numbers(argc, argv);
	arr = malloc(arr_size * sizeof(int));
	if (!arr)
		return (1);
	if (!parse_numbers(argc, argv, arr))
	{
		free(arr);
		return (1);
	}
	stackA = create_stack(arr, arr_size);
	stackB = NULL;
	print_stack(stackA);
	free(arr);
	return (0);
}
