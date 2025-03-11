/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:49 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/11 19:22:11 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int *tab, int nbr, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (tab[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_int(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->nbr, 1);
		write(1, "\n", 1);
		stack = stack->next;
	}
}

int	count_split_args(char **split)
{
	int	i;
	int	count;

	if (!split)
		return (0);
	i = 0;
	count = 0;
	while (split[i])
	{
		count++;
		i++;
	}
	return (count);
}
