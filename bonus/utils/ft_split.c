/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:26:25 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/11 00:40:56 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
		if (is_delimiter(str[i]))
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

static int	process_word(char *str, char **alloc_str, int *i, int p)
{
	int	j;

	while (is_delimiter(str[*i]))
		(*i)++;
	if (str[*i] == '\0')
		return (0);
	j = *i;
	while (str[*i] && !is_delimiter(str[*i]))
		(*i)++;
	alloc_str[p] = copy_word(&str[j], *i - j);
	if (!alloc_str[p])
	{
		while (p >= 0)
			free(alloc_str[p--]);
		free(alloc_str);
		return (0);
	}
	return (1);
}

static char	**allocate_words(char *str, int word_count)
{
	int		i;
	int		p;
	char	**alloc_str;

	alloc_str = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!alloc_str)
		return (NULL);
	i = 0;
	p = 0;
	while (str[i])
	{
		if (!process_word(str, alloc_str, &i, p))
			return (NULL);
		p++;
	}
	alloc_str[p] = NULL;
	return (alloc_str);
}

char	**ft_split(char *str)
{
	int		word_count;
	char	**alloc_str;

	if (!str)
		return (NULL);
	word_count = count_word(str);
	alloc_str = allocate_words(str, word_count);
	return (alloc_str);
}
