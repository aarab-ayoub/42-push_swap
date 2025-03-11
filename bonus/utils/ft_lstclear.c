/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:21 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/11 00:40:56 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*ptr;
	t_stack	*next_node;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		next_node = ptr->next;
		del(ptr->nbr);
		free(ptr);
		ptr = next_node;
	}
	*lst = NULL;
}
