/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:26:19 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/11 12:26:20 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	while (*string)
	{
		if (*string == (char)searchedChar)
			return ((char *)string);
		string++;
	}
	if (*string == (char)searchedChar)
		return ((char *)string);
	return (NULL);
}
