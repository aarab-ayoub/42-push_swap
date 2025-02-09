/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:08:15 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/09 12:44:22 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static int	count_word(char *str)
{
	int	in_word;
	int	count;
	int	i;

	in_word = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_delimiter(str[i]))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*copy_word(char *src, int len)
{
	int		i;
	char	*word;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_alloc(char **alloc, int j)
{
	while (j >= 0)
	{
		free(alloc[j]);
		j--;
	}
	free(alloc);
}

static int	find_next_word(char *str, int *start)
{
	int	i;

	i = *start;
	while (str[i] && is_delimiter(str[i]))
		i++;
	*start = i;
	while (str[i] && !is_delimiter(str[i]))
		i++;
	return (i - *start);
}

char	**ft_split(char *str)
{
	int		j;
	int		len;
	int		start;
	char	**alloc;

	j = 0;
	start = 0;
	if (!str)
		return (NULL);
	alloc = (char **)malloc((count_word(str) + 1) * sizeof(char *));
	if (!alloc)
		return (NULL);
	while (str[start])
	{
		len = find_next_word(str, &start);
		if (len > 0)
		{
			alloc[j] = copy_word(&str[start], len);
			if (!alloc[j])
			{
				free_alloc(alloc, j - 1);
				return (NULL);
			}
			j++;
			start += len;
		}
	}
	alloc[j] = NULL;
	return (alloc);
}
