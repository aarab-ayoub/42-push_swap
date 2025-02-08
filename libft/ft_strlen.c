/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:01:46 by ayaarab           #+#    #+#             */
/*   Updated: 2024/10/30 19:20:56 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen( const char *theString )
{
	size_t	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}
