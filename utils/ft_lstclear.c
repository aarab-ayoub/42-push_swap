/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:08:54 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/09 12:08:55 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		next_node = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = next_node;
	}
	*lst = NULL;
}
