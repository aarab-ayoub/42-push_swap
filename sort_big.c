/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:11:07 by ayaarab           #+#    #+#             */
/*   Updated: 2025/03/03 01:16:01 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_stack **stackA, t_stack **stackB)
{
	int	len;
	int	i;

	len = ft_lstsize(*stackA);
	i = 0;
	while (i < len)
	{
		pb(stackA, stackB);
		i++;
	}
}
void	final_rotate(t_stack **stackA, t_stack **stackB)
{
	;
}
void	sort_big(t_stack **stackA, t_stack **stackB)
{
	;
}
