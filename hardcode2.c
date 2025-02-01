#include "push_swap.h"

void	sort_dos(t_stack **stack_a)
{
	int a = (*stack_a)->nbr;
	int b = (*stack_a)->next->nbr;

	if (a > b)
		sa(stack_a);
	
}