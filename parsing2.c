/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:05:52 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/02 02:41:17 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_single_arg(char *arg, int *arr, int index)
{
	if (!is_valid_int(arg) || is_duplicate(arr, ft_atoi(arg), index))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	arr[index] = ft_atoi(arg);
	return (1);
}

static int	process_string_arg(char **split_args, int *arr, int *index)
{
	int	j;

	j = 0;
	while (split_args[j])
	{
		if (!is_valid_int(split_args[j]) || is_duplicate(arr,
				ft_atoi(split_args[j]), *index))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		arr[(*index)++] = ft_atoi(split_args[j]);
		j++;
	}
	return (1);
}

int	count_numbers(int argc, char **argv)
{
	int		i;
	int		count;
	char	**split_args;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			split_args = ft_split(argv[i]);
			count += count_split_args(split_args);
			free_split(split_args);
		}
		else
			count++;
		i++;
	}
	return (count);
}

int	parse_numbers(int argc, char **argv, int *arr)
{
    int		i;
    int		k;
    char	**split_args;

    i = 1;
    k = 0;
    while (i < argc)
    {
        if (ft_strchr(argv[i], ' '))
        {
            split_args = ft_split(argv[i]);
            if (!process_string_arg(split_args, arr, &k))
            {
                free_split(split_args);
                return (0);
            }
            free_split(split_args);
        }
        else
        {
            if (!process_single_arg(argv[i], arr, k))
                return (0);
            k++;
        }
        i++;
    }
    return (1);
}
