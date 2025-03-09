/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:31:39 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/09 20:54:55 by ayoub            ###   ########.fr       */
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

// static void	handle_sorting(t_stack **stack_a, int len, t_stack **stack_b)
// {
// 	if (!is_sorted(stack_a))
// 	{
// 		if (len < 3)
// 			sort_dos(stack_a);
// 		else if (len < 4)
// 			sort_trois(stack_a);
// 		else if (len == 5)
// 			sort_cinq(stack_a, stack_b);
// 		else
// 			sort_big(stack_a, stack_b);
// 	}
// }

static int	init_and_validate(int argc, int *arr_size, char **argv, int **arr)
{
	if (argc < 2)
		return (1);
	*arr_size = count_numbers(argc, argv);
	*arr = malloc(*arr_size * sizeof(int));
	if (!arr)
		return (1);
	if (!parse_numbers(argc, argv, *arr))
	{
		free(arr);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int arr_size;
    int *arr;

    stack_b = NULL;
    if (init_and_validate(argc, &arr_size, argv, &arr) != 0)
        return (1);
    stack_a = create_stack(arr, arr_size);
    if (ft_lstsize(stack_a) == 0)
    {
        free(arr);
        free_stack(stack_a);
        return (1);
    }
    if (check_operations(&stack_a, &stack_b) != 0)
    {
        free(arr);
        free_stack(stack_a);
        free_stack(stack_b);
        write(2, "Error\n", 6);
        return (1);
    }
    if (is_sorted(&stack_a) && !stack_b)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free(arr);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
