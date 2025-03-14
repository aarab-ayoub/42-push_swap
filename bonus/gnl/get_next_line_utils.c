/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:31:14 by ayoub             #+#    #+#             */
/*   Updated: 2025/03/11 00:40:56 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

size_t	ft_strlen_g(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_g(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen_g(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_over, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_over)
	{
		left_over = (char *)malloc(1 * sizeof(char));
		left_over[0] = '\0';
	}
	if (!left_over || !buffer)
		return (NULL);
	str = malloc((ft_strlen_g(left_over) + ft_strlen_g(buffer) + 1)
			* sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_over)
		while (left_over[++i] != '\0')
			str[i] = left_over[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen_g(left_over) + ft_strlen_g(buffer)] = '\0';
	free(left_over);
	return (str);
}
