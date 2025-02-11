/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:26:25 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/11 12:26:31 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_word(char *str)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

static char	*copy_word(char *src, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		p;
	int		word_count;
	char	**alloc_str;
	int		len;

	i = 0;
	p = 0;
	word_count = count_word(str);
	alloc_str = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!alloc_str)
		return (NULL);
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '\0')
			break ;
		j = i;
		while (str[i] && str[i] != 32 && (str[i] < 9 || str[i] > 13))
			i++;
		len = i - j;
		alloc_str[p] = copy_word(&str[j], len);
		if (!alloc_str[p])
		{
			while (p >= 0)
				free(alloc_str[p--]);
			free(alloc_str);
			return (NULL);
		}
		p++;
	}
	alloc_str[p] = NULL;
	return (alloc_str);
}
